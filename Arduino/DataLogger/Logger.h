#ifndef Logger_h
#define Logger_h

#include "Arduino.h"
#include "Lcd.h"
#include "CarData.h"

const char BeginLogging = 'B';

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
    stream->write(",");
    stream->print(currentTime);
    stream->write(",");
    stream->print(CarData::RearSpeed);
    stream->write(",");
    stream->print(CarData::Rpm);
    stream->write(",");
    stream->print(CarData::Gear);
    stream->write(",");
    stream->print(CarData::XG);
    stream->write(",");
    stream->print(CarData::YG);
    stream->write(",");
    stream->print(CarData::ZG);
    stream->write(",");
    stream->print(CarData::IntakeTemp);
    stream->write(",");
    stream->print(CarData::Stationary);
    stream->write(",");
    stream->print(CarData::Braking);
    stream->write("\n");
    delay(500);
  }
};

#endif

