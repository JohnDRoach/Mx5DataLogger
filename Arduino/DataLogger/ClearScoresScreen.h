#ifndef ClearScoresScreen_h
#define ClearScoresScreen_h

#include "Buttons.h"
#include "Screen.h"
#include "ClearScoresSuccessScreen.h"


class ClearScoresScreen : 
public Screen
{
private:
  Screen* successScreen;
public:
  ClearScoresScreen(Lcd* lcd, Screen* next) : 
  Screen(lcd)
  {
    nextScreen = next;
    successScreen = new ClearScoresSuccessScreen(lcd);
    successScreen->SetNextScreen(next);
  }

  void Init()
  {
    lcd->GoSmall();
    lcd->printLine("To clear scores:");
    lcd->printLine("- Alt button -->");
    lcd->printLine("- Press change screen");
    lcd->NewLine();
    lcd->printLine("To cancel:");
    lcd->printLine("- Alt button <--");
    lcd->printLine("- Press change screen");
  }

  void RefreshValues()
  {
  }

  Screen* NextScreen()
  {
    if(Buttons::AlternateMode())
    {
      return successScreen;
    }

    return nextScreen;
  }
};

#endif


