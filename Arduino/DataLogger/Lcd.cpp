#include "Lcd.h"

const uint8_t StartCommand = 0x7C;
const uint8_t Clear = 0x00;
const uint8_t ChangeXCoord = 0x18;
const uint8_t ChangeYCoord = 0x19;
const uint8_t ToggleFont = 0x08;

const uint8_t BigFontWidth = 11;
const uint8_t BigFontHeight = 16;
const uint8_t SmallFontWidth = 6;
const uint8_t SmallFontHeight = 8;

Lcd* Lcd::instance = 0;

Lcd* Lcd::Instance()
{
  if(instance == 0)
    instance = new Lcd(7, 115200);
  return instance;
}

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
  SendCommand(Clear);
}

void Lcd::NewLine()
{
  serialIO.write("\n");
  SendCommand(ChangeXCoord);
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

void Lcd::MoveBigCursor(uint8_t line, uint8_t charPos)
{
  // Line, Y
  SendCommand(ChangeYCoord);
  serialIO.write((line - 1) * BigFontHeight);
  // Character Position, X
  SendCommand(ChangeXCoord);
  serialIO.write((charPos - 1) * BigFontWidth);
}

void Lcd::MoveSmallCursor(uint8_t line, uint8_t charPos)
{
  // Line, Y
  SendCommand(ChangeYCoord);
  serialIO.write((line - 1) * SmallFontHeight);
  // Character Position, X
  SendCommand(ChangeXCoord);
  serialIO.write((charPos - 1) * SmallFontWidth);
}

void Lcd::ChangeFont()
{
  SendCommand(ToggleFont);
  isBig = !isBig;
}

void Lcd::SendCommand(uint8_t command)
{
  serialIO.write(StartCommand);
  serialIO.write(command);
}

int Lcd::CalculateLength(int value)
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
  
  return length;
}

uint8_t Lcd::GetCharacterPositionDifference(int value, int totalChars)
{
  int length = CalculateLength(value);

  if(length < totalChars)
  {
    return totalChars - length;
  }

  return 0;
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

void Lcd::printBigInt(int value, uint8_t line, uint8_t characterPosition, int totalChars)
{
  characterPosition += GetCharacterPositionDifference(value, totalChars);
  MoveBigCursor(line, characterPosition);
  serialIO.print(value);
}

void Lcd::printSmallInt(int value, uint8_t line, uint8_t characterPosition, int totalChars)
{
  characterPosition += GetCharacterPositionDifference(value, totalChars);
  MoveSmallCursor(line, characterPosition);
  serialIO.print(value);
}

void Lcd::print(float value)
{
  serialIO.print(value);
}

void Lcd::printBigFloat(float value, uint8_t line, uint8_t characterPosition, int totalChars)
{
  characterPosition += GetCharacterPositionDifference(value, totalChars);
  MoveBigCursor(line, characterPosition);
  serialIO.print(value);
}

void Lcd::printSmallFloat(float value, uint8_t line, uint8_t characterPosition, int totalChars)
{
  characterPosition += GetCharacterPositionDifference(value, totalChars);
  MoveSmallCursor(line, characterPosition);
  serialIO.print(value);
}





