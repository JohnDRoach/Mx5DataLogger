#ifndef ClearScoresSuccessScreen_h
#define ClearScoresSuccessScreen_h

#include "Screen.h"
#include "HighScores.h"

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
    HighScores::ClearScores();

    lcd->GoBig();
    lcd->NewLine();
    lcd->printLine(F("   Scores"));
    lcd->print(F("  Cleared!"));
  }

  void RefreshValues()
  {
  }
};

#endif

