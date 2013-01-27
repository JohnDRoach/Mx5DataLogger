#ifndef Screen_h
#define Screen_h

#include "Lcd.h"

class Screen
{
private:
  Screen* nextScreen;

protected:
  Lcd* lcd;

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
    nextScreen = screen;
  }
};

#endif

