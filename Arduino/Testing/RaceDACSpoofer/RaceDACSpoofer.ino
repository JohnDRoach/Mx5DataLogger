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

char buffer[300];
int counter = 1;
int other = 1;

void setup() 
{
  delay(3000);  // Wait for LCD and Bluetooth module to wake
  setupBlueToothConnection();
}

void loop()
{
  //CheckSumAndSend("RC2,,5118,,,,0,0,0,124,0,0,0,0,0,0");
  String mess = "RC2,,";
  mess += counter++;
  
  for(int i = 0; i < 13; i++)
  {
    mess += ',';
    mess += other++;
  }

  CheckSumAndSend(mess);

  delay(200);
}

void CheckSumAndSend(String mess)
{
  int lengthofstring = mess.length();
  int checksum = 0;
  int i = 0;

  for( i=0; i<lengthofstring; i++)
    checksum ^= mess[i];

  Serial.write('$');

  mess.toCharArray(buffer, 300);
  Serial.write(buffer);

  Serial.write('*');

  if(checksum < 16)
    Serial.write('0');

  Serial.print(checksum, HEX);

  Serial.write(13);
  Serial.write(10);  
}

void setupBlueToothConnection()
{
  Serial.begin(115200);
  Serial.print(F("\r\n+INQ=1\r\n"));  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.
}







