#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

const int alternateModePin = 4;
const int screenChangePin = 5;

class Buttons
{
private:
  static const long debounceTime = 50;

  static long startedDebouncingAt;
  static int lastButtonState;
  static int buttonState;

public:
  static boolean ScreenChange()
  {
    return digitalRead(screenChangePin);
//    int pinState = digitalRead(screenChangePin);
//    long currentTime = millis();
//
//    if(pinState != lastButtonState) {
//      startedDebouncingAt = currentTime;
//    }
//
//    lastButtonState = pinState;
//
//    if((currentTime - startedDebouncingAt) > debounceTime) {
//      buttonState = pinState;
//    }
//
//    return buttonState == HIGH;
  }

  static boolean AlternateMode()
  {
    return digitalRead(alternateModePin);
  }
};

#endif





