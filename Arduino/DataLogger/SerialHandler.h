#ifndef SerialHandler_h
#define SerialHandler_h

#include <Lcd.h>
#include "Arduino.h"
#include "Buttons.h"
#include "Settings.h"
#include "HighScores.h"

const byte SOH = 0x01;

class SerialHandler
{
private:
  Lcd* lcd;

  void FindAndProcessCommand()
  {
    while(Serial.available() > 0)
    {
      if(Serial.read() == SOH)
        HandleCommandString();
    }
  }

  void HandleCommandString()
  {
    char command[4];
    Serial.readBytes(command, 3);
    command[3] = '\0';

    lcd->print("Command: ");
    lcd->printLine(command);

    if(strcmp(command, "SET") == 0)
    {
      Serial.write("ACK");
      while(Serial.available() <= 0);
      lcd->printLine("Applying Settings...");
      Settings::LoadNewValuesFromStreamAndPersist(&Serial);
    }
    else if(strcmp(command, "HSL") == 0)
    {
      lcd->printLine("Sending High Scores.");
      HighScores::SendScoresVia(&Serial);
    }
  }

public:
  SerialHandler(Lcd* lcd) :
  lcd(lcd)
  {
  }

  void DataAvailable()
  {
    lcd->ClearDisplay();
    lcd->printLine("Serial Data Received");

    FindAndProcessCommand();

    lcd->printLine("Press button to exit");
    while(!Buttons::ScreenChange());
    while(Buttons::ScreenChange());
  }
};

#endif











