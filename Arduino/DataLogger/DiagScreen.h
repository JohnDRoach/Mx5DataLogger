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
    lcd->printLine("---- Diagnostics ---");
    lcd->NewLine();
    lcd->printLine("Launch RPM:");
    lcd->printLine(" Tolerance:");
    lcd->print(" Shift RPM:");
  }

  void RefreshValues()
  {
    lcd->MoveSmallCursor(2, 5);
    if(CarData::Stationary)
      lcd->print("Stationary");
    else
      lcd->print("Moving");

    lcd->printSmallInt(Settings::LaunchRpm, 3, 14, 4);
    lcd->printSmallInt(Settings::LaunchRpmTolerance, 4, 14, 4);
    lcd->printSmallInt(Settings::ShiftRpm, 5, 14, 4);
  }
};

#endif




