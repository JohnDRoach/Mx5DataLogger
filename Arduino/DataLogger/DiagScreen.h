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
    lcd->printLine("  Diag Screen");
  }

  void RefreshValues()
  {
    lcd->printLine("D");
  }
};

#endif


