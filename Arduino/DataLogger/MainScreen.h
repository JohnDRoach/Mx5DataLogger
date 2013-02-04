#ifndef MainScreen_h
#define MainScreen_h

#include "Screen.h"
#include "CarData.h"

class MainScreen : 
public Screen
{
public:
  MainScreen(Lcd* lcd) : 
  Screen(lcd)
  {
  }

  void Init()
  {
    lcd->GoBig();
    lcd->MoveBigCursor(1, 7);
    lcd->print(F("KM/H"));
    lcd->MoveBigCursor(2, 7);
    lcd->print(F("RPM"));
    lcd->MoveBigCursor(3, 3);
    lcd->print(F("GEAR"));

    lcd->GoSmall();
    lcd->MoveSmallCursor(7, 1);
    lcd->print(F("x"));
    lcd->MoveSmallCursor(7, 8);
    lcd->print(F("y"));
    lcd->MoveSmallCursor(7, 15);
    lcd->print(F("z"));

    lcd->MoveSmallCursor(8, 1);
    lcd->print(F("Intake Temp:"));
  }

  void RefreshValues()
  {
    lcd->GoBig();
    lcd->printBigInt(CarData::RearSpeed, 1, 3, 3);
    lcd->printBigInt(CarData::Rpm, 2, 2, 4);
    lcd->printBigInt(CarData::Gear, 3, 9, 1);

    lcd->GoSmall();
    lcd->printSmallFloat(CarData::XG, 7, 2, 2);
    lcd->printSmallFloat(CarData::YG, 7, 9, 2);
    lcd->printSmallFloat(CarData::ZG, 7, 16, 2);
    lcd->printSmallInt(CarData::IntakeTemp, 8, 14, 3);
  }
};

#endif

