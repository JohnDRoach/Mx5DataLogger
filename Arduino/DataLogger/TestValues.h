#ifndef TestValues_h
#define TestValues_h

#include "Buttons.h"

class TestValues
{
public:
  static int testCounter;
  static boolean alternateButtonState;
  static boolean screenChangeState;

  static void Update()
  {
    testCounter++;
    alternateButtonState = Buttons::AlternateMode();
    screenChangeState = Buttons::ScreenChange();
  }
};

#endif

