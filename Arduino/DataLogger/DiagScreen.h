#ifndef DiagScreen_h
#define DiagScreen_h

#include "Screen.h"

class DiagScreen : public Screen
{
public:
  DiagScreen(Lcd* lcd) : base(lcd)
  {
  }

  void Init()
  {
    lcd->printLine("Diag Screen");
  }
  
  void RefreshValues()
  {
    lcd->printLine("Update..");
  }
};

#endif

