#include "ScreenHandler.h"
#include "MainScreen.h"
#include "HighScoreScreen.h"
#include "DiagScreen.h"
#include "CarData.h"

ScreenHandler::ScreenHandler() :
screenChangeLastState(false),
lcd(Lcd::Instance())
{
  Screen* screen1 = new MainScreen(lcd);
  Screen* screen2 = new HighScoreScreen(lcd);
  Screen* screen3 = new DiagScreen(lcd);

  screen1->SetNextScreen(screen2);
  screen2->SetNextScreen(screen3);
  screen3->SetNextScreen(screen1);

  currentScreen = screen1;
}

void ScreenHandler::Start()
{
  lcd->ClearDisplay();
  currentScreen->Init();
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
  if(CarData::Braking)
  {
    lcd->ToggleBacklight();
  }
  else
  {
    currentScreen = currentScreen->NextScreen();
    Start();
  }
}

void ScreenHandler::RefreshValues()
{
  currentScreen->RefreshValues();
}



