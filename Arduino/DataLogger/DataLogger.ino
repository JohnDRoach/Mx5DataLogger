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
//Display Mode || Settings
//Logging Mode (No LCD updates)

#include "SendOnlySoftwareSerial.h"

const int LCDPin = 13;
SendOnlySoftwareSerial lcd(LCDPin);

void setup() 
{
  lcd.begin(115200);
  initialiseLCD();
  setupBlueToothConnection();
} 

void initialiseLCD()
{
  lcd.write("Testing\n");
}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  delay(2000);  // Wait for device to be fully awake
  Serial.print("\r\n+INQ=1\r\n");  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.
}

void loop() 
{
  
  if (Serial.available() > 0) {
    lcd.write(Serial.read());
  }
}


