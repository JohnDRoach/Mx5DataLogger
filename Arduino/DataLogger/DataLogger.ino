#include <TimerOne.h>
#include <MsTimer2.h>
#include "Lcd.h"
#include "Buttons.h"
#include "ScreenHandler.h"
#include "TestValues.h"


const float VERSION = 0.5;

// Pin Definitions
const int speedSensorPin = 2;
//const int rpmSensorPin = 3;
//const int brakeSwitchPin = 6;
const int shiftLightPin = 8;
const int videoStartPin = 9;
const int xGPin = A0;
const int yGPin = A1;
const int zGPin = A2;
//const int intakeTempPin = A3;

// Interrupts
const int rearSpeedSensorInterrupt = 0;
const int rpmSensorInterrupt = 1;

// Volatile Interrupt/Timer variables
volatile unsigned int rearSpeed = 0;
volatile unsigned int rearSpeedCounter = 0;
volatile unsigned int rpm = 0;
volatile unsigned int rpmCounter = 0;

Lcd* lcd = Lcd::Instance();
ScreenHandler screenHandler;

void setup() 
{
  attachInterrupt(rearSpeedSensorInterrupt, RearSpeedSensorInterrupt, RISING);
  attachInterrupt(rpmSensorInterrupt, RpmSensorInterrupt, RISING);
  pinMode(alternateModePin, INPUT);
  pinMode(screenChangePin, INPUT);
  pinMode(shiftLightPin, OUTPUT);
  pinMode(videoStartPin, OUTPUT);

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
  delay(2000);  // Wait for device to be fully awake
  Serial.print("\r\n+INQ=1\r\n");  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.

  if (Serial.available() > 0)
    lcd->printLine("OK");  
  else
    lcd->printLine(" X");
}

void mountSDCard()
{
  lcd->print("Mounting SDCard..");
  lcd->printLine("OK");
}

void loadSettings()
{
  lcd->print("Load Settings....");
  lcd->printLine("OK");
}

void loadHighScores()
{
  lcd->print("Loading Scores...");
  lcd->printLine("OK");
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
  //  if (Serial.available() > 0) {
  //    lcd->write(Serial.read());
  //  }

  TestValues::Update();
  delay(50);

  // Update CarData()
  // Send Bluetooth Data()
  // Update HighScoreData()
  // Update DiagnosticsData()
}


//volatile unsigned int rearSpeed = 0;
//volatile unsigned int rearSpeedCounter = 0;
//volatile unsigned int rpm = 0;
//volatile unsigned int rpmCounter = 0;

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
  
  //rearSpeed = speedCounter * 1.629; // this is per second
  rearSpeed = rearSpeedCounter * 3.257; // this is per 500ms
  rearSpeedCounter = 0;
  
  //rpm = rpmCounter * 60; // this is per second  
  rpm = rpmCounter * 120; // this is per 500ms
  rpmCounter = 0;  
}

