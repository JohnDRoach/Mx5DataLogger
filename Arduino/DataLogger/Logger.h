#ifndef Logger_h
#define Logger_h

#include "Arduino.h"
#include "Lcd.h"
#include "CarData.h"


class Logger
{
private:
  static unsigned long logTime;
  static unsigned long startTime;
public:
  static boolean Logging;

  static void EnterLoggingMode()
  {
    Logging = true;
  }

  static void ExitLoggingMode()
  {
    Logging = false;
  }

  static void ResetCounter()
  {
    logTime = 0;
    startTime = millis();
  }

  static void Log(Stream* stream)
  {
    unsigned long currentTime = millis();
    logTime = currentTime - startTime;
    stream->print(logTime);
    stream->print(F(","));
    stream->print(currentTime);
    stream->print(F(","));
    stream->print(CarData::RearSpeed);
    stream->print(F(","));
    stream->print(CarData::Rpm);
    stream->print(F(","));
    stream->print(CarData::Gear);
    stream->print(F(","));
    stream->print(CarData::XG);
    stream->print(F(","));
    stream->print(CarData::YG);
    stream->print(F(","));
    stream->print(CarData::ZG);
    stream->print(F(","));
    stream->print(CarData::IntakeTemp);
    stream->print(F(","));
    stream->print(CarData::Stationary);
    stream->print(F(","));
    stream->print(CarData::Braking);
    stream->print(F("\n"));
    delay(500);
  }
};

#endif

