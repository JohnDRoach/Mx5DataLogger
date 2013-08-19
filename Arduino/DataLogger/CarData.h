#ifndef CarData_h
#define CarData_h

#include "Arduino.h"
#include "Settings.h"

const int brakeSwitchPin = 6;
const int shiftLightPin = 8;
const int xGPin = A0;
const int yGPin = A1;
const int zGPin = A2;
//const int intakeTempPin = A3;  // This will become the 2-step output

class CarData
{
private:
  static int rpmOverSpeed;

  static int CalculateGear()
  {
    if(RearSpeed == 0)
      return 0;

    rpmOverSpeed = Rpm / RearSpeed;

    if(rpmOverSpeed > 120)
      return 1;
    else if(rpmOverSpeed > 70)
      return 2;
    else if(rpmOverSpeed > 50)
      return 3;
    else if(rpmOverSpeed > 35)
      return 4;
    else
      return 5;
  }

  static void LaunchShiftLight()
  {
    if(Stationary)
    {
      if((Settings::LaunchRpm - Settings::LaunchRpmTolerance < Rpm) && (Rpm < Settings::LaunchRpm + Settings::LaunchRpmTolerance))
        digitalWrite(shiftLightPin, HIGH);
      else
        digitalWrite(shiftLightPin, LOW);
    }
    else
    {
      if(Rpm > Settings::ShiftRpm)
        digitalWrite(shiftLightPin, HIGH);
      else
        digitalWrite(shiftLightPin, LOW);
    }
  }

public:
  static int RearSpeed;
  static int Rpm;
  static int Gear;
  static float XG;
  static float YG;
  static float ZG;
  static boolean Stationary;
  static boolean Braking;
  static int LastDistanceTravelled;

  static void Update(unsigned int rearSpeed, unsigned int rpm, boolean stationary, unsigned int lastDistanceTravelled)
  {
    RearSpeed = rearSpeed;
    Rpm = rpm;
    Gear = CalculateGear();

    // 0V = 0
    // 3.3V = 1023
    // 0G = 3.3/2 = 1023/2 ~ 512
    float temp = 0.0;
    temp = analogRead(xGPin);
    XG = temp * 0.0133 - 4.92;
    temp = analogRead(yGPin);
    YG = temp * 0.0139 - 5.18;
    temp = analogRead(zGPin);
    ZG = temp * 0.0125 - 4.75;

    Stationary = stationary;
    Braking = digitalRead(brakeSwitchPin);
    LastDistanceTravelled = lastDistanceTravelled;

    LaunchShiftLight();
  }
};

#endif













