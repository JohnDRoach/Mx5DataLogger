#include "ScreenHandler.h"
//#include "MainScreen.h"
//#include "HighScoreScreen.h"
//#include "DiagScreen.h"

ScreenHandler::ScreenHandler() :
screenChangeLastState(false),
lcd(Lcd::Instance())
{
}

void ScreenHandler::ChangeScreen(boolean state)
{
  if(state == true && screenChangeLastState == false)
  {
    ChangeScreen();
  }
  
  screenChangeLastState = state;
}

void ScreenHandler::ChangeScreen()
{
  currentScreen = currentScreen->NextScreen();
  lcd->ClearDisplay();
  currentScreen->Init();
}

void ScreenHandler::RefreshValues()
{
  currentScreen->RefreshValues();
}

