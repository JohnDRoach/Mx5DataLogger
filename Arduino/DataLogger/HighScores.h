#ifndef HighScores_h
#define HighScores_h

#include "CarData.h"

class HighScores
{
private:
  static boolean lastStationary;
  static unsigned long sessionStartTime;

  static void Persist()
  {
    File highScoresFile = SD.open("highscor.txt", O_WRITE | O_CREAT | O_TRUNC);

    if(!highScoresFile)
      return;

    highScoresFile.print(top60);
    highScoresFile.write("\n");
    highScoresFile.print(top100);
    highScoresFile.write("\n");
    highScoresFile.print(top400m);
    highScoresFile.write("\n");
    highScoresFile.print(topSpeed);
    highScoresFile.write("\n");
    highScoresFile.print(topNSG);
    highScoresFile.write("\n");
    highScoresFile.print(topEWG);
    highScoresFile.write("\n");    
    highScoresFile.close();
  }

public:
  static float top60; // low positive
  static float live60;
  static float top100; // low positive
  static float live100;
  static float top400m; // low positive
  static float live400m;
  static int topSpeed; // high positive
  static int liveSpeed;
  static float topNSG; // Z - high positive
  static float liveNSG;
  static float topEWG; // Y - high modulus
  static float liveEWG;

  static int Init()
  {
    File highScoresFile = SD.open("highscor.txt");

    if(!highScoresFile)
      return 1;

    if(highScoresFile.available() < 0)
    {
      highScoresFile.close();
      return 2;
    }

    if(!LoadValuesFromStream(&highScoresFile))
    {
      highScoresFile.close();
      return 3;
    }

    highScoresFile.close();
    return 0;
  }

  static boolean LoadValuesFromStream(Stream* stream)
  {
    char temp[8];

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    float tempTop60 = atof(temp);

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    float tempTop100 = atof(temp);

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    float tempTop400m = atof(temp);

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    int tempTopSpeed = atoi(temp);

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    float tempTopNSG = atof(temp);

    memset(temp, 0, 8);
    stream->readBytesUntil('\n', temp, 8);
    float tempTopEWG = atof(temp);

    if(tempTop60 <= 0 || tempTop100 <= 0 || tempTop400m <= 0)
    {
      return false;
    }
    else
    {
      top60 = tempTop60;
      top100 = tempTop100;
      top400m = tempTop400m;
      topSpeed = tempTopSpeed;
      topNSG = tempTopNSG;
      topEWG = tempTopEWG;
      return true;
    }
  }

  static void SendScoresVia(Stream* stream)
  {
    File highScoresFile = SD.open("highscor.txt");

    if(!highScoresFile)
      return;

    while(highScoresFile.available() > 0)
      stream->write(highScoresFile.read());

    highScoresFile.close();
  }

  static void ClearScores()
  {
    top60 = 999.99;
    top100 = 999.99;
    top400m = 999.99;
    topSpeed = 0;
    topNSG = 0.0;
    topEWG = 0.0;
    Persist();
  }

  static void Update()
  {
    liveSpeed = CarData::RearSpeed;
    liveNSG = CarData::ZG;
    liveEWG = CarData::YG;
    
    if(CarData::Stationary)
    {
      sessionStartTime = 0;
      lastStationary = true;
      return;
    }
    else if(lastStationary == true)
    {
      sessionStartTime = millis();
      live60 = 0;
      live100 = 0;
      live400m = 0;
      return;
    }

    boolean updateRequired = false;
    float difference = (millis() - sessionStartTime) / 1000;

    if(live60 == 0 && CarData::RearSpeed > 59)
    {
      live60 = difference;
      if(live60 < top60)
      {
        top60 = live60;
        updateRequired = true;
      }
    }

    if(live100 == 0 && CarData::RearSpeed > 99)
    {
      live100 = difference;
      if(live100 < top100)
      {
        top100 = live100;
        updateRequired = true;
      }
    }

    if(live400m == 0 && CarData::LastDistanceTravelled > 399)
    {
      live400m = difference;
      if(live400m < top400m)
      {
        top400m = live400m;
        updateRequired = true;
      }
    }

    
    if(liveSpeed > topSpeed)
    {
      topSpeed = liveSpeed;
      updateRequired = true;
    }

        
    if(liveNSG > topNSG)
    {
      topNSG = liveNSG;
      updateRequired = true;
    }

    
    if(liveEWG < 0)
      liveEWG *= -1;
    if(liveEWG > topEWG)
    {
      topEWG = liveEWG;
      updateRequired = true;
    }

    if(updateRequired)
    {
      Persist();
    }
  }
};

#endif

