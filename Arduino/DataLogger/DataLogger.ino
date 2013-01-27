// Notes
//Use switch on front panel for two modes.
//
//- Display  (RPM, Speed, Gear, Accelerations)
//- Settings (Launch RPM, Shift RPM)
//
//6500-7000
//3500-6500
//
//
//Display Mode || High Scores || Diagnostics
//Logging Mode (No LCD updates)

#include <TimerOne.h>
#include "Lcd.h"
#include "Buttons.h"
#include "TestValues.h"

const float VERSION = 0.3;

// Pin Definitions
const int speedSensorPin = 2;
//const int rpmSensorPin = 3;
//const int brakeSwitchPin = 6;
const int lcdPin = 7;
const int shiftLightPin = 8;
const int videoStartPin = 9;
const int xGPin = A0;
const int yGPin = A1;
const int zGPin = A2;
//const int intakeTempPin = A3;

Lcd lcd(lcdPin, 115200);

void setup() 
{
  pinMode(alternateModePin, INPUT);
  pinMode(screenChangePin, INPUT);
  pinMode(shiftLightPin, OUTPUT);
  pinMode(videoStartPin, OUTPUT);

  initialiseLCD();
  setupBlueToothConnection();
  loadHighScores();
  startLoggingTimer();
  lcd.NewLine();
  lcd.NewLine();
  countDown();
  startLcdTimer();
} 

void initialiseLCD()
{
  delay(2000); // Wait for LCD to become active
  lcd.ClearDisplay();
  lcd.GoSmall();
  lcd.print("-- DataLogger ");
  lcd.print(VERSION);
  lcd.print(" --");
  delay(2000);
}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  lcd.print("Bluetooth Init....");
  delay(2000);  // Wait for device to be fully awake
  Serial.print("\r\n+INQ=1\r\n");  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.
  lcd.printLine("OK");
}

void loadHighScores()
{
  lcd.print("Load High Scores..");
  delay(1500);
  lcd.printLine("OK");
}

void startLoggingTimer()
{
  lcd.print("Logger Timer......");
  delay(1500);
  lcd.printLine("OK");
}

void countDown()
{
  int count = 5;

  while(!Buttons::AlternateMode() && count > 0)
  {
    lcd.print(count);
    count--;
    delay(1000);
  }

  while(Buttons::AlternateMode())
  {
    if(count >= 0)
    {
      count = -1;
      lcd.NewLine();
      lcd.print("Unlock to continue.");
    }
  }
}

void startLcdTimer()
{
  Timer1.initialize(100000);  // 0.1 second period in microseconds
  Timer1.attachInterrupt(WriteToLCD);
  Timer1.start();
}

void loop() 
{
  //  if (Serial.available() > 0) {
  //    lcd.write(Serial.read());
  //  }

  TestValues::Update();
  delay(50);
}

void WriteToLCD()
{
  lcd.ClearDisplay();
  lcd.GoBig();

  lcd.print(TestValues::testCounter);
  lcd.NewLine();

  lcd.print(TestValues::testCounter, 10);
  lcd.NewLine();

  lcd.GoSmall();

  lcd.print(TestValues::testCounter);
  lcd.NewLine();

  lcd.print(TestValues::testCounter, 15);
  lcd.NewLine();

  lcd.print(TestValues::screenChangeState);
  lcd.NewLine();

  lcd.print(TestValues::alternateButtonState);
  lcd.NewLine();
}




