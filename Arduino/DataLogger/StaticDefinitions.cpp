#include "TestValues.h"

int TestValues::testCounter = 0;
boolean TestValues::alternateButtonState = false;
boolean TestValues::screenChangeState = false;

#include "Buttons.h"
long Buttons::startedDebouncingAt = 0;
int Buttons::lastButtonState = LOW;
int Buttons::buttonState = LOW;

