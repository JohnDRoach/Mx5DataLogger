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

#include "Lcd.h"

const int LCDPin = 13;
const long LCDBaud = 115200;
Lcd lcd(LCDPin, LCDBaud);

void setup() 
{
  setupBlueToothConnection();
  initialiseLCD();
} 

void initialiseLCD()
{
  //  delay(1000); // Uncomment this out if there is no delay before now since turn on.

  lcd.ClearDisplay();

  lcd.print("Line 1");
  lcd.NewLine();
  lcd.print("Line 2");
  lcd.NewLine();
  lcd.print("Line 3");
  lcd.NewLine();
  lcd.print("Line 4");
  lcd.NewLine();

  lcd.GoBig();

  lcd.print("Line 1 Big");
  lcd.NewLine();
  lcd.print("Line 2 Big");
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

  lcd.ClearDisplay();
  lcd.GoBig();

  lcd.print(counter);
  lcd.NewLine();

  lcd.print(counter, 10);
  //  lcd.print(counter);
  lcd.NewLine();

  lcd.GoSmall();

  lcd.print(counter);
  lcd.NewLine();

  lcd.print(counter, 11);
  //  lcd.print(counter);
  lcd.NewLine();

  lcd.print(counter);
  lcd.NewLine();

  lcd.print(counter, 20);
  //  lcd.print(counter);
  lcd.NewLine();

  counter++;
  delay(50);
}














