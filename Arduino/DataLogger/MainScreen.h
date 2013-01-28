#ifndef MainScreen_h
#define MainScreen_h

#include "Screen.h"

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
    lcd->print("KM/H");
    lcd->MoveBigCursor(2, 7);
    lcd->print("RPM");
    lcd->MoveBigCursor(3, 3);
    lcd->print("GEAR");

    lcd->GoSmall();
    lcd->MoveSmallCursor(7,1);
    lcd->print("x:");
    lcd->MoveSmallCursor(7,8);
    lcd->print("y:");
    lcd->MoveSmallCursor(7,15);
    lcd->print("z:");

    lcd->MoveSmallCursor(8,1);
    lcd->print("Intake Temp:");
  }

  void RefreshValues()
  {
    lcd->GoBig();
    lcd->printBigInt(999, 1, 3, 3);
    lcd->printBigInt(999, 2, 2, 4);
    lcd->printBigInt(5, 3, 9, 1);

    lcd->GoSmall();
    lcd->printSmallFloat(1.23, 7, 3, 1);
    lcd->printSmallFloat(4.56, 7, 10, 1);
    lcd->printSmallFloat(7.89, 7, 17, 1);
    lcd->printSmallInt(25, 8, 13, 3);
  }
};

#endif





