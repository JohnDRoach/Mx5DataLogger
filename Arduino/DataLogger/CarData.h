#ifndef CarData_h
#define CarData_h

const int xGPin = A0;
const int yGPin = A1;
const int zGPin = A2;
const int intakeTempPin = A3;

class CarData
{
public:
  static int rearSpeed;
  static int rpm;
  static int gear;
  static float xG;
  static float yG;
  static float zG;
  static float intakeTemp;

  static void Update(int rear, int revs)
  {
    rearSpeed = rear;
    rpm = revs;

    // Need to figure out this calculation!
    if(rearSpeed == 0)
      gear = 0;
    else
      gear = 5 - (rpm / rearSpeed) * 3;

    // 0V = 0
    // 3.3V = 1023
    // 0G = 3.3/2 = 1023/2 ~ 512
    float tep = 0.0;
    tep = analogRead(xGPin);
    xG = (tep - 512)/102.3;
    tep = analogRead(yGPin);
    yG = (tep - 512)/102.3;
    tep = analogRead(zGPin);
    zG = (tep - 512)/102.3;

    // Some multiplier what ever happens with the intake temp voltage
    tep = analogRead(intakeTempPin);
    intakeTemp = tep;
  }
};

#endif








