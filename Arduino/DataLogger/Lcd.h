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
  void SendCommand(uint8_t);
  int CalculateLength(int);
  uint8_t GetCharacterPositionDifference(int value, int totalChars);

public:
  static Lcd* Instance();
  Lcd(uint8_t transmitPin, long baudRate);
  ~Lcd();

  void ClearDisplay();
  void NewLine();
  void GoBig();
  void GoSmall();

  void MoveBigCursor(uint8_t,uint8_t);
  void MoveSmallCursor(uint8_t,uint8_t);

  void print(char*);
  void printLine(char*);
  void print(int);
  void printBigInt(int value, uint8_t line, uint8_t characterPosition, int totalChars);
  void printSmallInt(int value, uint8_t line, uint8_t characterPosition, int totalChars);
  void print(float);
  void printBigFloat(float value, uint8_t line, uint8_t characterPosition, int totalChars);
  void printSmallFloat(float value, uint8_t line, uint8_t characterPosition, int totalChars);
};

#endif





