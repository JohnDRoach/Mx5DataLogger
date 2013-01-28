#ifndef DiagScreen_h
#define DiagScreen_h

#include "Screen.h"
#include "CarData.h"
#include "DiagData.h"

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

    lcd->MoveSmallCursor(2, 1);
    lcd->print("Speed:");
    lcd->MoveSmallCursor(2, 12);
    lcd->print("RPM:");

    lcd->MoveSmallCursor(4, 1);
    lcd->print(" Gear:");

    lcd->MoveSmallCursor(5, 1);
    lcd->print("Launch RPM:");

    lcd->MoveSmallCursor(6, 1);
    lcd->print(" Shift RPM:");
  }

  void RefreshValues()
  {
    lcd->GoSmall();

    lcd->printSmallInt(CarData::RearSpeed, 2, 8, 3);
    lcd->printSmallInt(CarData::Rpm, 2, 17, 4);

    lcd->printSmallInt(DiagData::RearSpeedCount, 3, 8, 3);
    lcd->printSmallInt(DiagData::RpmCount, 3, 17, 4);

    lcd->printSmallInt(CarData::Gear, 4, 8, 1);
    lcd->MoveSmallCursor(4, 11);
    if(CarData::Stationary)
      lcd->print("Stationary");
    else
      lcd->print("Moving");

    lcd->printSmallInt(5500, 5, 14, 4); // Launch RPM from settings
    lcd->printSmallInt(6800, 6, 14, 4); // Shift RPM from settings
  }
};

#endif








