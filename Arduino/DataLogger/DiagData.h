#ifndef DiagData_h
#define DiagData_h

class DiagData
{
public:
  static int RearSpeedCount;
  static int RpmCount;

  static void Update(unsigned int rearSpeedCount, unsigned int rpmCount)
  {
    RearSpeedCount = rearSpeedCount;
    RpmCount = rpmCount;
  }
};

#endif











