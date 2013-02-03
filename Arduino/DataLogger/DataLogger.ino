#include <TimerOne.h>
#include <MsTimer2.h>
#include <SD.h>
#include <Lcd.h>
#include <SendOnlySoftwareSerial.h>
#include "Buttons.h"
#include "ScreenHandler.h"
#include "CarData.h"
#include "Settings.h"
#include "SerialHandler.h"
#include "Logger.h"
#include "HighScores.h"

const float VERSION = 1.0;

// Pin Definitions
const int speedSensorPin = 2;
const int rpmSensorPin = 3;
const int videoStartPin = 9;

// Interrupts
const int rearSpeedSensorInterrupt = 0;
const int rpmSensorInterrupt = 1;

// Volatile Interrupt/Timer variables
volatile unsigned int rearSpeed = 0;
volatile unsigned int rearSpeedCounter = 0;
volatile unsigned int rpm = 0;
volatile unsigned int rpmCounter = 0;

boolean stationary = true;
unsigned int lastDistanceTravelled = 0;

Lcd* lcd = Lcd::Instance();
ScreenHandler screenHandler;
SerialHandler serialHandler(lcd);

void setup() 
{
  attachInterrupt(rearSpeedSensorInterrupt, RearSpeedSensorInterrupt, RISING);
  attachInterrupt(rpmSensorInterrupt, RpmSensorInterrupt, RISING);
  pinMode(alternateModePin, INPUT);
  pinMode(screenChangePin, INPUT);
  pinMode(shiftLightPin, OUTPUT);
  pinMode(videoStartPin, OUTPUT);
  pinMode(10, OUTPUT);

  delay(3000);  // Wait for LCD and Bluetooth module to wake

  initialiseLCD();
  setupBlueToothConnection();
  mountSDCard();
  loadSettings();
  loadHighScores();
  startCounterTimer();
  lcd->NewLine();  // Just making sure message is at the bottom
  holdIfAlternateMode();
  startLcd();
} 

void initialiseLCD()
{
  lcd->ClearDisplay();
  lcd->GoSmall();
  lcd->print("-- DataLogger ");
  lcd->print(VERSION);
  lcd->print(" --");
}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  lcd->print("Bluetooth Init...");
  Serial.print(F("\r\n+INQ=1\r\n"));  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.

  if (Serial.available() > 0)
    lcd->printLine("OK");  
  else
    lcd->printLine("B1");  // Didn't receive a response
}

void mountSDCard()
{
  lcd->print("Mounting SDCard..");

  // 0 = OK
  // S1 = Card Missing
  // S2 = No FAT16/FAT32 Partition
  // S3 = Already open or not initialised
  writeStatus("S", SD.begin(10));
}

void loadSettings()
{
  lcd->print("Load Settings....");

  // L1 = File not found
  // L2 = File is Empty
  // L3 = Invalid data
  writeStatus("L", Settings::Init());
}

void loadHighScores()
{
  lcd->print("Loading Scores...");

  // H1 = File not found
  // H2 = File is Empty
  // H3 = Invalid data
  writeStatus("H", HighScores::Init());
}

void writeStatus(char* codePrefix, int errorCode)
{
  if(errorCode)
  {
    lcd->print(codePrefix);
    lcd->print(errorCode);
    lcd->NewLine();
  }
  else
  {
    lcd->printLine("OK");      
  }
}

void startCounterTimer()
{
  lcd->print("Start Counters...");
  MsTimer2::set(500, counterTimerFired); // 500ms period, 2Hz.
  // I would like this to be 20 - 50 Hz but need to look at sensible rates based on counter increment speed.
  MsTimer2::start();
  lcd->printLine("OK");
}

void holdIfAlternateMode()
{
  if(Buttons::AlternateMode())
    lcd->print("Unlock to continue.");

  while(Buttons::AlternateMode());
}

void startLcd()
{
  screenHandler.Start();
  Timer1.initialize(100000);  // 0.1 second period in microseconds
  Timer1.attachInterrupt(WriteToLCD);
}

void WriteToLCD()
{
  screenHandler.ChangeScreen(Buttons::ScreenChange());
  screenHandler.RefreshValues();
}

void loop()
{
  if (Serial.available() > 0) {
    Timer1.stop();
    serialHandler.DataAvailable();
    LogIfNeedBe();
    startLcd();
  }

  UpdateCarData();
  // Send Bluetooth Data() (If I wanted gauges on the phone then I'll need something like this)
  HighScores::Update();
}

void LogIfNeedBe()
{
  if(Logger::Logging)
  {
    lcd->ClearDisplay();
    lcd->GoBig();
    lcd->MoveBigCursor(2, 1);
    lcd->printLine(" Bluetooth");
    lcd->printLine(" Logging");

    UpdateCarData();
    StartCamera();
    Logger::ResetCounter();

    while(!Buttons::ScreenChange())
    {
      // Without high scores this logs greater than 300 Hz!!
      Logger::Log(&Serial);
      UpdateCarData();
      HighScores::Update();  // Maybe remove this if it slows down the logging.
    }

    lcd->ClearDisplay();
    lcd->GoBig();
    lcd->MoveBigCursor(2, 1);
    lcd->printLine(" Logging");
    lcd->printLine(" Finished");
    while(Buttons::ScreenChange());
    Logger::ExitLoggingMode();
  }
}

void UpdateCarData()
{
  stationary = (rearSpeedCounter + rearSpeed) == 0;
  if(stationary)
    lastDistanceTravelled = 0;
  CarData::Update(rearSpeed, rpm, stationary, lastDistanceTravelled);
}

void StartCamera()
{
  digitalWrite(videoStartPin, HIGH);
  delay(2);
  digitalWrite(videoStartPin, LOW);
  delay(1); // Insert calibration delay here
}

void RearSpeedSensorInterrupt()
{
  rearSpeedCounter++;
}

void RpmSensorInterrupt()
{
  rpmCounter++;
}

void counterTimerFired()
{
  //Multipliers are based on period of MsTimer2

  lastDistanceTravelled += 0.45 * rearSpeedCounter;

  //rearSpeed = speedCounter * 1.629; // this is per second
  rearSpeed = rearSpeedCounter * 3.257; // this is per 500ms
  rearSpeedCounter = 0;

  //rpm = rpmCounter * 60; // this is per second
  rpm = rpmCounter * 120; // this is per 500ms
  rpmCounter = 0;  
}







