#ifndef HighScoreScreen_h
#define HighScoreScreen_h

#include "Buttons.h"
#include "ClearScoresScreen.h"
#include "Screen.h"
#include "HighScores.h"

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
    lcd->printLine(F("- High Scores Board-"));
    lcd->printLine(F("        Top    Live"));
    lcd->printLine(F("0-60"));
    lcd->printLine(F("0-100"));
    lcd->printLine(F("400m"));
    lcd->printLine(F("Speed"));
    lcd->printLine(F("NS G"));
    lcd->printLine(F("EW G"));
  }

  void RefreshValues()
  {
    //    lcd->printLine("        Top    Live");
    //    lcd->printLine("       123.12 123.12");
    //    lcd->printLine("        123    123");
    //    lcd->printLine("12345678901234567890");

    lcd->printSmallFloat(HighScores::top60, 3, 8, 3);
    lcd->printSmallFloat(HighScores::live60, 3, 15, 3);

    lcd->printSmallFloat(HighScores::top100, 4, 8, 3);
    lcd->printSmallFloat(HighScores::live100, 4, 15, 3);

    lcd->printSmallFloat(HighScores::top400m, 5, 8, 3);
    lcd->printSmallFloat(HighScores::live400m, 5, 15, 3);

    lcd->printSmallInt(HighScores::topSpeed, 6, 10, 3);
    lcd->printSmallInt(HighScores::liveSpeed, 6, 17, 3);

    lcd->printSmallFloat(HighScores::topNSG, 7, 8, 3);
    lcd->printSmallFloat(HighScores::liveNSG, 7, 15, 3);

    lcd->printSmallFloat(HighScores::topEWG, 8, 8, 3);
    lcd->printSmallFloat(HighScores::liveEWG, 8, 15, 3);
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







