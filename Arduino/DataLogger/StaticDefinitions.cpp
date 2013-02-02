#include "Buttons.h"
long Buttons::startedDebouncingAt = 0;
int Buttons::lastButtonState = LOW;
int Buttons::buttonState = LOW;

#include "CarData.h"
int CarData::rpmOverSpeed = 0;
int CarData::RearSpeed = 0;
int CarData::Rpm = 0;
int CarData::Gear = 0;
float CarData::XG = 0.0;
float CarData::YG = 0.0;
float CarData::ZG = 0.0;
float CarData::IntakeTemp = 0.0;
boolean CarData::Stationary = true;
boolean CarData::Braking = true;

#include "DiagData.h"
int DiagData::RearSpeedCount = 0;
int DiagData::RpmCount = 0;

#include "Settings.h"
int Settings::LaunchRpm = 5500;
int Settings::LaunchRpmTolerance = 122;
int Settings::ShiftRpm = 6800;
