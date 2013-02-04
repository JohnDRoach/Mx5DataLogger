#ifndef DiagScreen_h
#define DiagScreen_h

#include "Screen.h"
#include "Settings.h"

class DiagScreen : 
public Screen
{
public:
  DiagScreen(Lcd* lcd) : 
  Screen(lcd)
  {
  }

  void Init()
  {
    lcd->GoSmall();
    lcd->printLine(F("---- Diagnostics ---"));
    lcd->NewLine();
    lcd->printLine(F("Launch RPM:"));
    lcd->printLine(F(" Tolerance:"));
    lcd->print(F(" Shift RPM:"));
  }

  void RefreshValues()
  {
    lcd->MoveSmallCursor(2, 5);
    if(CarData::Stationary)
      lcd->print(F("Stationary"));
    else
      lcd->print(F("Moving"));

    lcd->printSmallInt(Settings::LaunchRpm, 3, 14, 4);
    lcd->printSmallInt(Settings::LaunchRpmTolerance, 4, 14, 4);
    lcd->printSmallInt(Settings::ShiftRpm, 5, 14, 4);
  }
};

#endif




