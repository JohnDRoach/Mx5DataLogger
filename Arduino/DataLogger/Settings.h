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

    if(settingsFile.available() < 0)
      return 2;

    char temp[6];

    memset(temp, 0, 6);
    settingsFile.readBytesUntil('\n', temp, 6);
    int launchRpm = atoi(temp);

    memset(temp, 0, 6);
    settingsFile.readBytesUntil('\n', temp, 6);
    int shiftRpm = atoi(temp);

    settingsFile.close();

    if(launchRpm == 0 || shiftRpm == 0)
    {
      return 3;
    }
    else
    {
      LaunchRpm = launchRpm;
      ShiftRpm = shiftRpm;
      return 0;
    }
  }

  static void StoreAndLoadNewValues(int launchRpm, int shiftRpm)
  {
    LaunchRpm = launchRpm;
    ShiftRpm = shiftRpm;
    // Save new values to disc
  }
};

#endif














