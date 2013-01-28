#include "TestValues.h"

int TestValues::testCounter = 0;
boolean TestValues::alternateButtonState = false;
boolean TestValues::screenChangeState = false;

#include "Buttons.h"
long Buttons::startedDebouncingAt = 0;
int Buttons::lastButtonState = LOW;
int Buttons::buttonState = LOW;

#include "CarData.h"
int CarData::rearSpeed = 0;
int CarData::rpm = 0;
int CarData::gear = 0;
float CarData::xG = 0.0;
float CarData::yG = 0.0;
float CarData::zG = 0.0;
float CarData::intakeTemp = 0.0;

