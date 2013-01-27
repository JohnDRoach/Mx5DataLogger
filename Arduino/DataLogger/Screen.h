#ifndef Screen_h
#define Screen_h

#include "Lcd.h"

class Screen
{
private:
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

  void SetNextScreen(Screen* screen)
  {
    nextScreen = screen;
  }

  virtual Screen* NextScreen()
  {
    return nextScreen;
  }
};

#endif

