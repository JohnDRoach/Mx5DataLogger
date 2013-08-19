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

void setup() 
{
  delay(3000);  // Wait for LCD and Bluetooth module to wake

  setupBlueToothConnection();

  delay(3000);

  crap();
}

void loop()
{
  int counter = 1;
  int other = 1;

  String stringOne = "$RC2,,";

  while(true)
  {
    
    
    delay(200);
  }  
}

void crap()
{
  Serial.write("$RC2,,5118,,,,0,0,0,124,0,0,0,0,0,0*05\r\n");
  CheckSumAndSend("RC2,,5118,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5119,,,,0,0,0,124,0,0,0,0,0,0*04");
  CheckSumAndSend("RC2,,5119,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5120,,,,0,0,0,124,0,0,0,0,0,0*0E");
  CheckSumAndSend("RC2,,5120,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5121,,,,0,0,0,124,0,0,0,0,0,0*0F");
  CheckSumAndSend("RC2,,5121,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5122,,,,0,0,0,124,0,0,0,0,0,0*0C");
  CheckSumAndSend("RC2,,5122,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5123,,,,0,0,0,124,0,0,0,0,0,0*0D");
  CheckSumAndSend("RC2,,5123,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5124,,,,0,0,0,124,0,0,0,0,0,0*0A");
  CheckSumAndSend("RC2,,5124,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5125,,,,0,0,0,0,0,0,0,0,0,0*0C");
  CheckSumAndSend("RC2,,5125,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5126,,,,0,0,0,0,0,0,0,0,0,0*0F");
  CheckSumAndSend("RC2,,5126,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5127,,,,0,0,0,0,0,0,0,0,0,0*0E");
  CheckSumAndSend("RC2,,5127,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5128,,,,0,0,0,0,0,0,0,0,0,0*01");
  CheckSumAndSend("RC2,,5128,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5129,,,,0,0,0,0,0,0,0,0,0,0*00");
  CheckSumAndSend("RC2,,5129,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5130,,,,0,0,0,0,0,0,0,0,0,0*08");
  CheckSumAndSend("RC2,,5130,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5131,,,,0,0,0,0,0,0,0,0,0,0*09");
  CheckSumAndSend("RC2,,5131,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5132,,,,0,0,0,0,0,0,0,0,0,0*0A");
  CheckSumAndSend("RC2,,5132,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5133,,,,0,0,0,0,0,0,0,0,0,0*0B");
  CheckSumAndSend("RC2,,5133,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5134,,,,0,0,0,0,0,0,0,0,0,0*0C");
  CheckSumAndSend("RC2,,5134,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5135,,,,0,0,0,0,0,0,0,0,0,0*0D");
  CheckSumAndSend("RC2,,5135,,,,0,0,0,0,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5136,,,,0,0,0,124,0,0,0,0,0,0*09");
  CheckSumAndSend("RC2,,5136,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5137,,,,0,0,0,124,0,0,0,0,0,0*08");
  CheckSumAndSend("RC2,,5137,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5138,,,,0,0,0,124,0,0,0,0,0,0*07");
  CheckSumAndSend("RC2,,5138,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
  Serial.write("$RC2,,5139,,,,0,0,0,124,0,0,0,0,0,0*06");
  CheckSumAndSend("RC2,,5139,,,,0,0,0,124,0,0,0,0,0,0");
  Serial.write("\r\n");
  delay(200);
}

void CheckSumAndSend(String mess)
{
  //char mystring[] = "$RC2,,1,,,,1234,2,1,2,3,4,5,6,7,8*";
  //int lengthofstring = strlen(mystring);
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
  //lcd->print(F("Bluetooth Init..."));
  Serial.print(F("\r\n+INQ=1\r\n"));  // Tell BlueToothBee to advertise itself
  delay(2000); // This delay is required.

  //if (Serial.available() > 0)
  //  lcd->printLine(F("OK"));  
  //else
  //  lcd->printLine(F("B1"));  // Didn't receive a response
}




