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
#include "Lcd.h"

const int LCDPin = 13;
SendOnlySoftwareSerial lcd(LCDPin);

void setup() 
{
  setupBlueToothConnection();
  initialiseLCD();
} 

void initialiseLCD()
{
//  delay(1000); // Uncomment this out if there is no delay before now since turn on.
  
  lcd.begin(115200);

  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x00);

  //lcd.write((uint8_t)0x7c);
  //lcd.write((uint8_t)0x04);

  lcd.write("Line 1\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.write("Line 2\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.write("Line 3\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.write("Line 4\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);

  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x08);  

  lcd.write("Line 1 Big\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.write("Line 2 Big\n");
  delay(2000);
}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  delay(2000);  // Wait for device to be fully awake
  Serial.print("\r\n+INQ=1\r\n");  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.
}

int counter = 0;

void loop() 
{
  //  if (Serial.available() > 0) {
  //    lcd.write(Serial.read());
  //  }

  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x00);

  lcd.print(counter);
  lcd.write("\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.print(counter);
  lcd.write("\n");
  
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x08);
  
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.print(counter);
  lcd.write("\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.print(counter);
  lcd.write("\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);  

  lcd.print(counter);
  lcd.write("\n");
  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x18);
  lcd.write((uint8_t)0x00);
  lcd.print(counter);
  lcd.write("\n");

  lcd.write((uint8_t)0x7c);
  lcd.write((uint8_t)0x08);

  counter++;
  delay(50);
}








