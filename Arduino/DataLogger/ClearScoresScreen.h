#ifndef ClearScoresScreen_h
#define ClearScoresScreen_h

#include "Screen.h"

class ClearScoresScreen : 
public Screen
{
public:
  ClearScoresScreen(Lcd* lcd) : base(lcd)
  {
  }

  void Init()
  {
    lcd->printLine("To clear scores:");
    lcd->printLine("- Engage Alt button");
    lcd->printLine("- Press change screen");
  }

  void RefreshValues()
  {
  }
};

#endif


