#ifndef MainScreen_h
#define MainScreen_h

#include "Screen.h"

class MainScreen : public Screen
{
public:
  MainScreen(Lcd* lcd) : base(lcd)
  {
  }

  void Init()
  {
    lcd->printLine("Main Screen");
  }
  
  void RefreshValues()
  {
    lcd->printLine("Update");
  }
};

#endif

