#ifndef Lcd_h
#define Lcd_h

//#include <inttypes.h>
//#include <Stream.h>
#include "Arduino.h"
#include "SendOnlySoftwareSerial.h"

class Lcd
{
private:
static Lcd* instance;
  boolean isBig;
  SendOnlySoftwareSerial serialIO;
  
  void ChangeFont();

public:
static Lcd* Instance();
  Lcd(uint8_t transmitPin, long baudRate);
  ~Lcd();

  void ClearDisplay();
  void NewLine();
  void GoBig();
  void GoSmall();

  void print(char*);
  void printLine(char*);
  void print(int);
  void print(int, int);
  void print(float);
  void print(double);
  void print(long);
  void print(boolean);
};

#endif

