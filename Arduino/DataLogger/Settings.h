#ifndef Settings_h
#define Settings_h

#include <SD.h>

class Settings
{
public:
  static int LaunchRpm;
  static int ShiftRpm;

  static int Init()
  {
    File settingsFile = SD.open("settings.txt");

    if(!settingsFile)
      return 1;

    char temp[] = { 
      0, 0, 0, 0, 0
    };

    if(settingsFile.available() < 0)
    {
      return 2;
    }

    char read = settingsFile.read();
    int count = 0;
    while(read != '\n')
    {
      temp[count] = read;
      read = settingsFile.read();
      count++;
    }

    LaunchRpm = atoi(temp);

    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    temp[3] = 0;
    temp[4] = 0;

    read = settingsFile.read();
    count = 0;
    while(read != '\n')
    {
      temp[count] = read;
      read = settingsFile.read();
      count++;
    }
    
    ShiftRpm = atoi(temp);

    settingsFile.close();

    if(LaunchRpm == 0 || ShiftRpm == 0)
      return 3;
    else
      return 0;
  }

  static void StoreAndLoadNewValues(int launchRpm, int shiftRpm)
  {
    LaunchRpm = launchRpm;
    ShiftRpm = shiftRpm;
    // Save new values to disc
  }
};

#endif









