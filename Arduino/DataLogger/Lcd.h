#ifndef Lcd_h
#define Lcd_h

//#include <inttypes.h>
//#include <Stream.h>
#include "SendOnlySoftwareSerial.h"

class Lcd
{
private:
  boolean isbig;
  SendOnlySoftwareSerial serialIO;

public:
  Lcd(uint8_t transmitPin, long baudRate);
  ~Lcd();

  void ClearDisplay();
  void NewLine();
  void GoBig();
  void GoSmall();

  void print(char*);
  void print(int);
  void print(int, int);
  void print(float);
  void print(double);
  void print(long);
};

#endif

