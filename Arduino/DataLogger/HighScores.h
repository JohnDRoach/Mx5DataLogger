#ifndef HighScores_h
#define HighScores_h

#include <SD.h>
#include "Arduino.h"

class HighScores
{
public:
  static void SendScoresVia(Stream* stream)
  {
    File highScoresFile = SD.open("highscores.txt");

    if(!highScoresFile)
      return;

    while(highScoresFile.available() > 0)
      stream->write(highScoresFile.read());

    highScoresFile.close();
  }
};

#endif

