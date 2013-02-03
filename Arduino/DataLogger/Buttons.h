#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

const int alternateModePin = 4;
const int screenChangePin = 5;

class Buttons
{
public:
  static boolean ScreenChange()
  {
    return digitalRead(screenChangePin);
  }

  static boolean AlternateMode()
  {
    return digitalRead(alternateModePin);
  }
};

#endif





