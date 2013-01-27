#ifndef HighScoreScreen_h
#define HighScoreScreen_h

#include "Screen.h"

class HighScoreScreen : public Screen
{
public:
  HighScoreScreen(Lcd* lcd) : base(lcd)
  {
  }

  void Init()
  {
    lcd->printLine("High Score");
  }
  
  void RefreshValues()
  {
    lcd->printLine("Update.");
  }
  
  Screen* NextScreen()
  {
    return nextScreen;
  }
};

#endif

