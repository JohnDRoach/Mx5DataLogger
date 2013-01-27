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
    lcd->GoSmall();
    lcd->printLine("  Main Screen");
  }

  void RefreshValues()
  {
    lcd->printLine("M");
  }
};

#endif



