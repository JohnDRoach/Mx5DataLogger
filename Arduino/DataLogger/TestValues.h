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
    TestValues::testCounter++;
    TestValues::alternateButtonState = Buttons::AlternateMode();
    TestValues::screenChangeState = Buttons::ScreenChange();
  }
};

int TestValues::testCounter = 0;
boolean TestValues::alternateButtonState = false;
boolean TestValues::screenChangeState = false;

#endif

