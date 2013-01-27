#ifndef ClearScoresSuccessScreen_h
#define ClearScoresSuccessScreen_h

#include "Screen.h"

class ClearScoresSuccessScreen : public Screen
{
public:
  ClearScoresSuccessScreen(Lcd* lcd) : base(lcd)
  {
  }

  void Init()
  {
    lcd->printLine("Scores Cleared!");
  }
  
  void RefreshValues()
  {
  }
};

#endif

