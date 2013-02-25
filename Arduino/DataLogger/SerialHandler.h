#ifndef SerialHandler_h
#define SerialHandler_h

#include <Lcd.h>
#include "Arduino.h"
#include "Buttons.h"
#include "Settings.h"
#include "HighScores.h"
#include "Logger.h"

const byte SOH = 0x01;

class SerialHandler
{
private:
  Lcd* lcd;

  boolean FindStartCharacter()
  {
    while(Serial.available() > 0)
    {
      if(Serial.read() == SOH)
        return true;
    }

    return false;
  }

  void HandleCommandString()
  {
    char command[4];
    Serial.readBytes(command, 3);
    command[3] = '\0';

    lcd->print(F("Command: "));
    lcd->printLine(command);

    if(strcmp(command, "SET") == 0)
    {
      SendACK();
      while(Serial.available() <= 0);
      lcd->printLine(F("Applying Settings..."));
      Settings::LoadNewValuesFromStreamAndPersist(&Serial);
    }
    else if(strcmp(command, "HSL") == 0)
    {
      SendACK();
      lcd->printLine(F("Sending High Scores."));
      HighScores::SendScoresVia(&Serial);
    }
    else if(strcmp(command, "LOG") ==0)
    {
      SendACK();
      Logger::EnterLoggingMode();
      lcd->printLine(F("On exit you will be"));
      lcd->printLine(F("    in logging mode."));
    }
    else
    {
      lcd->printLine(F("Invalid Command!"));
    }
  }

  void SendACK()
  {
    Serial.print(F("ACK"));
  }

public:
  SerialHandler(Lcd* lcd) :
  lcd(lcd)
  {
  }

  void DataAvailable()
  {
    if(!FindStartCharacter())
      return;

    lcd->ClearDisplay();
    lcd->GoSmall();
    lcd->printLine(F("Serial Data Received"));
    HandleCommandString();

    lcd->GoSmall();
    lcd->printLine(F("Press button to exit"));
    while(!Buttons::ScreenChange());
    while(Buttons::ScreenChange());
    delay(20);
  }
};

#endif















