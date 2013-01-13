#include <SoftwareSerial.h>

const int LCDPin = 13;
SoftwareSerial lcd(LCDPin); // TX

void setup() 
{
  lcd.begin(115200);
  setupBlueToothConnection();
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
  //  char blah = 'a';
  //  lcd.write(blah++);
  //  delay(1000);
  //Typical Bluetoth command - response simulation:

  //Type 'a' from PC Bluetooth Serial Terminal
  //See Bluetooth Bee - Wiki for instructions
  //  digitalWrite(13, LOW);
  while (Serial.available() > 0) {
    lcd.write(Serial.read());
  }

  //  if(Serial.read() == 'a')
  //  {
  //    Serial.print("You are connected");
  //    //You can write you BT communication logic here
  //  }
}


