//#include <TimerOne.h>
//#include <MsTimer2.h>
#include <SD.h>
#include <Lcd.h>
#include <SendOnlySoftwareSerial.h>
//#include "Buttons.h"
//#include "ScreenHandler.h"
//#include "CarData.h"
//#include "Settings.h"
//#include "SerialHandler.h"
//#include "Logger.h"
//#include "HighScores.h"

const float VERSION = 1.0;

// Pin Definitions
//const int speedSensorPin = 2;
//const int rpmSensorPin = 3;
//const int videoStartPin = 9;

// Interrupts
//const int rearSpeedSensorInterrupt = 0;
//const int rpmSensorInterrupt = 1;

// Volatile Interrupt/Timer variables
//volatile unsigned int rearSpeed = 0;
//volatile unsigned int rearSpeedCounter = 0;
//volatile unsigned int rearSpeedHistory[3];
//volatile unsigned int rpm = 0;
//volatile unsigned int rpmCounter = 0;
//volatile unsigned int rpmHistory[3];

//boolean stationary = true;
//unsigned int lastDistanceTravelled = 0;

//Lcd* lcd = Lcd::Instance();
//ScreenHandler screenHandler;
//SerialHandler serialHandler(lcd);

void setup() 
{
  //attachInterrupt(rearSpeedSensorInterrupt, RearSpeedSensorInterrupt, RISING);
  //attachInterrupt(rpmSensorInterrupt, RpmSensorInterrupt, FALLING);
  //pinMode(alternateModePin, INPUT);
  //pinMode(screenChangePin, INPUT);
  //pinMode(shiftLightPin, OUTPUT);
  //pinMode(videoStartPin, OUTPUT);
  //pinMode(10, OUTPUT);

  delay(3000);  // Wait for LCD and Bluetooth module to wake

  //initialiseLCD();
  setupBlueToothConnection();

  delay(3000);

  crap();
  //while(true)
  //{
  //Serial.write("$RC2,,");
  //Serial.print(i++);
  //Serial.write(",,,,1234,1,1,2,3,4,5,6,7,8*CC");
  //Serial.write(13);
  //Serial.write(10);

  //char mystring[] = "$RC2,,1,,,,1234,2,1,2,3,4,5,6,7,8*";
  //int lengthofstring = strlen(mystring);
  //int checksum=0, i;

  //for( i=0; i<lengthofstring; i++)
  //    checksum ^= mystring[i];

  //printf("\nchecksum of the string\n\t%s\nis %02X",mystring,checksum);

  //Serial.write(mystring);

  //if(checksum < 16)
  //{
  //  Serial.write('0');
  //}

  //Serial.print(checksum, HEX);
  //Serial.write(13);
  //Serial.write(10);

  //delay(200);
  //}

  //mountSDCard();
  //loadSettings();
  //loadHighScores();
  //digitalWrite(shiftLightPin, HIGH);
  //startCounterTimer();
  //lcd->NewLine();  // Just making sure message is at the bottom
  //holdIfAlternateMode();
  //digitalWrite(shiftLightPin, LOW);
  //startLcd();
} 

void crap()
{
  Serial.write("$RC2,,5118,,,,0,0,0,124,0,0,0,0,0,0*05");SendEnd();
  delay(200);
  Serial.write("$RC2,,5119,,,,0,0,0,124,0,0,0,0,0,0*04");SendEnd();
  delay(200);
  Serial.write("$RC2,,5120,,,,0,0,0,124,0,0,0,0,0,0*0E");SendEnd();
  delay(200);
  Serial.write("$RC2,,5121,,,,0,0,0,124,0,0,0,0,0,0*0F");SendEnd();
  delay(200);
  Serial.write("$RC2,,5122,,,,0,0,0,124,0,0,0,0,0,0*0C");SendEnd();
  delay(200);
  Serial.write("$RC2,,5123,,,,0,0,0,124,0,0,0,0,0,0*0D");SendEnd();
  delay(200);
  Serial.write("$RC2,,5124,,,,0,0,0,124,0,0,0,0,0,0*0A");SendEnd();
  delay(200);
  Serial.write("$RC2,,5125,,,,0,0,0,0,0,0,0,0,0,0*0C");SendEnd();
  delay(200);
  Serial.write("$RC2,,5126,,,,0,0,0,0,0,0,0,0,0,0*0F");SendEnd();
  delay(200);
  Serial.write("$RC2,,5127,,,,0,0,0,0,0,0,0,0,0,0*0E");SendEnd();
  delay(200);
  Serial.write("$RC2,,5128,,,,0,0,0,0,0,0,0,0,0,0*01");SendEnd();
  delay(200);
  Serial.write("$RC2,,5129,,,,0,0,0,0,0,0,0,0,0,0*00");SendEnd();
  delay(200);
  Serial.write("$RC2,,5130,,,,0,0,0,0,0,0,0,0,0,0*08");SendEnd();
  delay(200);
  Serial.write("$RC2,,5131,,,,0,0,0,0,0,0,0,0,0,0*09");SendEnd();
  delay(200);
  Serial.write("$RC2,,5132,,,,0,0,0,0,0,0,0,0,0,0*0A");SendEnd();
  delay(200);
  Serial.write("$RC2,,5133,,,,0,0,0,0,0,0,0,0,0,0*0B");SendEnd();
  delay(200);
  Serial.write("$RC2,,5134,,,,0,0,0,0,0,0,0,0,0,0*0C");SendEnd();
  delay(200);
  Serial.write("$RC2,,5135,,,,0,0,0,0,0,0,0,0,0,0*0D");SendEnd();
  delay(200);
  Serial.write("$RC2,,5136,,,,0,0,0,124,0,0,0,0,0,0*09");SendEnd();
  delay(200);
  Serial.write("$RC2,,5137,,,,0,0,0,124,0,0,0,0,0,0*08");SendEnd();
  delay(200);
  Serial.write("$RC2,,5138,,,,0,0,0,124,0,0,0,0,0,0*07");SendEnd();
  delay(200);
  Serial.write("$RC2,,5139,,,,0,0,0,124,0,0,0,0,0,0*06");SendEnd();
  delay(200);
}

void SendEnd()
{
  Serial.write(13);
  Serial.write(10);
}
//void initialiseLCD()
//{
//  lcd->ClearDisplay();
//  lcd->GoSmall();
//  lcd->print(F("-- DataLogger "));
//  lcd->print(VERSION);
//  lcd->print(F(" --"));
//}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  //lcd->print(F("Bluetooth Init..."));
  Serial.print(F("\r\n+INQ=1\r\n"));  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.

  //if (Serial.available() > 0)
  //  lcd->printLine(F("OK"));  
  //else
  //  lcd->printLine(F("B1"));  // Didn't receive a response
}

//void mountSDCard()
//{
//  lcd->print(F("Mounting SDCard.."));
//
//  // 0 = OK
//  // S1 = Card Missing
//  // S2 = No FAT16/FAT32 Partition
//  // S3 = Already open or not initialised
//  writeStatus("S", SD.begin(10));
//}
//
//void loadSettings()
//{
//  lcd->print(F("Load Settings...."));
//
//  // L1 = File not found
//  // L2 = File is Empty
//  // L3 = Invalid data
//  writeStatus("L", Settings::Init());
//}
//
//void loadHighScores()
//{
//  lcd->print(F("Loading Scores..."));
//
//  // H1 = File not found
//  // H2 = File is Empty
//  // H3 = Invalid data
//  writeStatus("H", HighScores::Init());
//}
//
//void writeStatus(char* codePrefix, int errorCode)
//{
//  if(errorCode)
//  {
//    lcd->print(codePrefix);
//    lcd->print(errorCode);
//    lcd->NewLine();
//  }
//  else
//  {
//    lcd->printLine(F("OK"));      
//  }
//}
//
//void startCounterTimer()
//{
//  lcd->print(F("Start Counters..."));
//  MsTimer2::set(250, counterTimerFired); // 250ms period, 4Hz.
//  // I would like this to be 20 - 50 Hz but need to look at sensible rates based on counter increment speed.
//  MsTimer2::start();
//  lcd->printLine(F("OK"));
//}
//
//void holdIfAlternateMode()
//{
//  if(Buttons::AlternateMode())
//    lcd->print(F("Unlock to continue."));
//
//  while(Buttons::AlternateMode());
//}
//
//void startLcd()
//{
//  screenHandler.Start();
//  Timer1.initialize(100000);  // 0.1 second period in microseconds
//  Timer1.attachInterrupt(WriteToLCD);
//}
//
//void WriteToLCD()
//{
//  screenHandler.ChangeScreen(Buttons::ScreenChange());
//  screenHandler.RefreshValues();
//}
//
void loop()
{
  //  if (Serial.available() > 0) {
  //    Timer1.stop();
  //    serialHandler.DataAvailable();
  //    LogIfNeedBe();
  //    startLcd();
  //  }
  //
  //  UpdateCarData();
  //  // Send Bluetooth Data() (If I wanted gauges on the phone then I'll need something like this)
  //  HighScores::Update();
}
//
//void LogIfNeedBe()
//{
//  if(Logger::Logging)
//  {
//    lcd->ClearDisplay();
//    lcd->GoBig();
//    lcd->MoveBigCursor(2, 1);
//    lcd->printLine(F(" Bluetooth"));
//    lcd->printLine(F(" Logging"));
//
//    UpdateCarData();
//    StartCamera();
//    Logger::ResetCounter();
//
//    unsigned long timeTracker = millis();
//
//    while(!Buttons::ScreenChange())
//    {
//      Logger::Log(&Serial);
//      UpdateCarData();
//      HighScores::Update();
//      while(millis() - timeTracker < 20);  // want to log at 50Hz, i.e. every 20ms
//      timeTracker = millis();
//    }
//
//    lcd->ClearDisplay();
//    lcd->GoBig();
//    lcd->MoveBigCursor(2, 1);
//    lcd->printLine(F(" Logging"));
//    lcd->printLine(F(" Finished"));
//    while(Buttons::ScreenChange());
//    while(!Buttons::ScreenChange());
//    delay(20);    
//    Logger::ExitLoggingMode();
//  }
//}
//
//void UpdateCarData()
//{
//  stationary = (rearSpeedCounter + rearSpeed) == 0;
//  if(stationary)
//    lastDistanceTravelled = 0;
//  CarData::Update(rearSpeed, rpm, stationary, lastDistanceTravelled);
//}
//
//void StartCamera()
//{
//  digitalWrite(videoStartPin, HIGH);
//  delay(2);
//  digitalWrite(videoStartPin, LOW);
//  delay(1); // Insert calibration delay here
//}
//
//void RearSpeedSensorInterrupt()
//{
//  rearSpeedCounter++;
//}
//
//void RpmSensorInterrupt()
//{
//  rpmCounter++;
//}
//
//void counterTimerFired()
//{
//  //Multipliers are based on period of MsTimer2
//
//  lastDistanceTravelled += 0.45 * rearSpeedCounter;
//
//  //rearSpeed = speedCounter * 1.629; // this is per second
//  //rearSpeed = rearSpeedCounter * 3.257; // this is per 500ms
//  if(rearSpeedCounter == 0 && rearSpeedHistory[0] == 0)
//  {
//    rearSpeed = 0;
//  }
//  else
//  {
//    rearSpeed = (rearSpeedHistory[2] + rearSpeedHistory[1] + rearSpeedHistory[0] + rearSpeedCounter) * 1.629;
//  }
//
//  rearSpeedHistory[2] = rearSpeedHistory[1];
//  rearSpeedHistory[1] = rearSpeedHistory[0];
//  rearSpeedHistory[0] = rearSpeedCounter;
//  rearSpeedCounter = 0;
//
//  //rpm = rpmCounter * 60; // this is per second
//  //rpm = rpmCounter * 120; // this is per 500ms
//  rpm = (rpmHistory[2] + rpmHistory[1] + rpmHistory[0] + rpmCounter) * 1.629;
//
//  rpmHistory[2] = rpmHistory[1];
//  rpmHistory[1] = rpmHistory[0];
//  rpmHistory[0] = rpmCounter;
//  rpmCounter = 0;  
//}
//
//
//


