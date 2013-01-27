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
    lcd->GoBig();
    lcd->printLine("   Clear");
    lcd->printLine("  Scores?");

    if(Buttons::AlternateMode())
    {
      lcd->printLine("    No");    
    }
    else
    {
      lcd->printLine("    Yes");    
    }
  }

  void RefreshValues()
  {
    lcd->ClearDisplay();
    Init();
  }

  Screen* NextScreen()
  {
    if(Buttons::AlternateMode())
    {
      return nextScreen;
    }
    
    return successScreen;
  }
};

#endif




