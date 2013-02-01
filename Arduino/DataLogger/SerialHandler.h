#ifndef SerialHandler_h
#define SerialHandler_h

#include "Arduino.h"
#include "Buttons.h"

class SerialHandler
{
private:

public:
  static void DataAvailable(Lcd* lcd)
  {
    lcd->ClearDisplay();
    lcd->printLine("Serial Data Recv");
    
    lcd->print(Serial.read());
    
    lcd->printLine("Press button to exit");
    while(!Buttons::ScreenChange());
  }
};

#endif














