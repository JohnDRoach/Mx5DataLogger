#include "Lcd.h"

Lcd::Lcd(uint8_t transmitPin, long baudRate);
  ~Lcd::Lcd();

  void Lcd::ClearDisplay();
  void Lcd::NewLine();
  void Lcd::GoBig();
  void Lcd::GoSmall();

  void Lcd::print(char*);
  void Lcd::print(int);
  void Lcd::print(int, int);
  void Lcd::print(float);
  void Lcd::print(double);
  void Lcd::print(long);
