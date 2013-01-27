#ifndef ClearScoresSuccessScreen_h
#define ClearScoresSuccessScreen_h

#include "Screen.h"

class ClearScoresSuccessScreen : 
public Screen
{
public:
  ClearScoresSuccessScreen(Lcd* lcd) : 
  Screen(lcd)
  {
  }

  void Init()
  {
    lcd->GoBig();
    lcd->NewLine();
    lcd->printLine(" Scores");
    lcd->printLine("Cleared!");
  }

  void RefreshValues()
  {
  }
};

#endif


