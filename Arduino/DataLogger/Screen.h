#ifndef Screen_h
#define Screen_h

#include "Lcd.h"
#include "Buttons.h"

class Screen
{
protected:
  Lcd* lcd;
  Screen* nextScreen;

public:
  Screen(Lcd* lcd) :
  lcd(lcd),
  nextScreen(0)
  {
  }

  virtual void Init();
  virtual void RefreshValues();

  virtual Screen* NextScreen()
  {
    return nextScreen;
  }

  void SetNextScreen(Screen* screen)
  {
    if(!Buttons::AlternateMode())
    {
      nextScreen = screen;
    }
  }
};

#endif



