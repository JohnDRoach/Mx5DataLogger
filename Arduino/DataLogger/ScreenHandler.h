#ifndef ScreenHandler_h
#define ScreenHandler_h

#include "Lcd.h"
#include "Screen.h"

class ScreenHandler
{
private:
  boolean screenChangeLastState;
  Screen* currentScreen;
  Lcd* lcd;
  
  void ChangeScreen();
  
public:
  ScreenHandler();

  void ChangeScreen(boolean state);

  void RefreshValues();
};

#endif

