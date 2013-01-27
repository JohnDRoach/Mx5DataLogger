#ifndef HighScoreScreen_h
#define HighScoreScreen_h

//#include "Buttons.h"
#include "ClearScoresScreen.h"
#include "Screen.h"

class HighScoreScreen : 
public Screen
{
private:
  Screen* clearScoresScreen;
public:
  HighScoreScreen(Lcd* lcd) : 
  Screen(lcd)
  {
    clearScoresScreen = new ClearScoresScreen(lcd, this);
  }

  void Init()
  {
    lcd->GoSmall();
    lcd->printLine("  High Score");
  }

  void RefreshValues()
  {
    lcd->printLine("H");
  }

  Screen* NextScreen()
  {
    if(Buttons::AlternateMode())
    {
      return clearScoresScreen;
    }

    return nextScreen;
  }
};

#endif

