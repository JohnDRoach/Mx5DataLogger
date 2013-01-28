#ifndef DiagScreen_h
#define DiagScreen_h

#include "Screen.h"

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
  }

  void RefreshValues()
  {
    static int test = 65500;
    lcd->printSmallInt(test, 4, 5, 5);
    test++;
  }
};

#endif




