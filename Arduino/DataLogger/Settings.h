#ifndef Settings_h
#define Settings_h

#include <SD.h>

class Settings
{
private:
  static boolean LoadValuesFromStream(Stream* stream)
  {
    char temp[6];

    memset(temp, 0, 6);
    stream->readBytesUntil('\n', temp, 6);
    int launchRpm = atoi(temp);

    memset(temp, 0, 6);
    stream->readBytesUntil('\n', temp, 6);
    int launchRpmTolerance = atoi(temp);

    memset(temp, 0, 6);
    stream->readBytesUntil('\n', temp, 6);
    int shiftRpm = atoi(temp);

    if(launchRpm <= 0 || launchRpmTolerance <= 0 || shiftRpm <= 0)
    {
      return false;
    }
    else
    {
      LaunchRpm = launchRpm;
      LaunchRpmTolerance = launchRpmTolerance;
      ShiftRpm = shiftRpm;
      return true;
    }
  }

  static void Persist()
  {
    File settingsFile = SD.open("settings.txt", O_WRITE | O_CREAT | O_TRUNC);

    if(!settingsFile)
      return;

    settingsFile.print(LaunchRpm);
    settingsFile.write("\n");
    settingsFile.print(LaunchRpmTolerance);
    settingsFile.write("\n");
    settingsFile.print(ShiftRpm);
    settingsFile.write("\n");
    settingsFile.close();
    delay(1000); // time for SD card?
  }

public:
  static int LaunchRpm;
  static int LaunchRpmTolerance;
  static int ShiftRpm;

  static int Init()
  {
    File settingsFile = SD.open("settings.txt");

    if(!settingsFile)
      return 1;

    if(settingsFile.available() < 0)
    {
      settingsFile.close();
      return 2;
    }

    if(!LoadValuesFromStream(&settingsFile))
    {
      settingsFile.close();
      return 3;
    }

    settingsFile.close();
    return 0;
  }

  static void LoadNewValuesFromStreamAndPersist(Stream* stream)
  {
    if(LoadValuesFromStream(stream))
      Persist();
  }
};

#endif























