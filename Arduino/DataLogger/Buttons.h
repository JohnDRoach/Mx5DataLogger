#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

const int alternateModePin = 4;
const int screenChangePin = 5;

class Buttons
{
private:
  const long debounceTime = 50;
  
  long startedDebouncingAt = 0;
  int lastButtonState = LOW;
  int buttonState = LOW;

public:
  boolean ScreenChange()
  {
    int pinState = digitalRead(screenChangePin);
    long currentTime = millis();

    if(pinState != lastButtonState) {
      startedDebouncingAt = currentTime;
    }

    lastButtonState = pinState;

    if((currentTime - startedDebouncingAt) > debounceTime) {
      buttonState = pinState;
    }

    return buttonState == HIGH;
  }

  boolean AlternateMode()
  {
    return digitalRead(alternateModePin);
  }
};

#endif




