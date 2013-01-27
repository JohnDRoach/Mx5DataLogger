#include "Lcd.h"

const uint8_t StartCommand = 0x7C;
const uint8_t Clear = 0x00;
const uint8_t ChangeXCoord = 0x18;
const uint8_t ToggleFont = 0x08;

Lcd::Lcd(uint8_t transmitPin, long baudRate) :
isBig(false),
serialIO(transmitPin)
{
  serialIO.begin(baudRate);
}

Lcd::~Lcd()
{
}

void Lcd::ClearDisplay()
{
  serialIO.write(StartCommand);
  serialIO.write(Clear);
}

void Lcd::NewLine()
{
  serialIO.write("\n");
  serialIO.write(StartCommand);
  serialIO.write(ChangeXCoord);
  serialIO.write((uint8_t)0x00);
}

void Lcd::GoBig()
{
  if(!isBig)
  {
    ChangeFont();
  }
}

void Lcd::GoSmall()
{
  if(isBig)
  {
    ChangeFont();
  }
}

void Lcd::ChangeFont()
{
  serialIO.write(StartCommand);
  serialIO.write(ToggleFont);
  isBig = !isBig;
}

void Lcd::print(char* value)
{
  serialIO.write(value);
}

void Lcd::printLine(char* value)
{
  print(value);
  NewLine();
}

void Lcd::print(int value)
{
  serialIO.print(value);
}

void Lcd::print(int value, int totalChars)
{
  int length = 1;
  int tempValue = value;

  if(value < 0)
  { 
    length++;
    tempValue *= -1;
  }

  while(tempValue > 9)
  {
    length++;
    tempValue /= 10;
  }

  if(length < totalChars)
  {
    serialIO.write(StartCommand);
    serialIO.write(ChangeXCoord);
    serialIO.write((uint8_t)(totalChars - length) * (isBig ? 11 : 6));
  }

  //  while(length < totalChars)
  //  {
  //    serialIO.print(' ');
  //    length++;
  //  }

  serialIO.print(value);
}

void Lcd::print(float value)
{
  serialIO.print(value);
}

void Lcd::print(double value)
{
  serialIO.print(value);
}

void Lcd::print(long value)
{
  serialIO.print(value);
}

void Lcd::print(boolean value)
{
  serialIO.print((int)value);
}

