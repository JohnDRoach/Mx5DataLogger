/*
 Data logging Instrument cluster section Simulator
 
 Designed for an ATTiny85
 
 */
//From some other guy
// const int wingTips = 0;                     // IC leg 5; red and green 3mm LED navigation lights for wingtips
// const int LDRpower = 4;                     // IC leg 3; power for LDR, turned off if it's daylight
// const int lightSensor = 3;                  // IC leg 2; LDR sensor reading
// const int redBeacon = 1;                    // IC leg 6; flashing red 3mm LED on tail
// const int headlight = 2;                    // IC leg 7; 2x 5mm white LEDs for landing lights 
//End from some other guy

#define INTERNAL2V56_NO_CAP (6)

const int TachPotPin = 3; // A1  // Was 1

const int ShiftUpPin = 2;        // Was 3
const int ShiftDownPin = 4;      // Was 4

int lastShiftSelection = 0;
const int NoShift = 0;
const int WasUp = 1;
const int WasDown = 2;

const int SpeedPulsePin = 0;    // Was 0
const int TachPulsePin = 1;     // Was 1

int gear = 0;

long lastTachPulseTime = 0;
long lastSpeedPulseTime = 0;

long timeBetweenRpmPulses = 0;  // ms
long timeBetweenSpeedPulses = 0;  // ms

// Debounce stuff
int counterUp = 0;       // how many times we have seen new value
int readingUp;           // the current value read from the input pin
int currentStateUp = LOW;    // the debounced input value
long timeUp = 0;         // the last time the output pin was sampled
int debounceCountUp = 10; // number of millis/samples to consider before declaring a debounced input

int counterDown = 0;       // how many times we have seen new value
int readingDown;           // the current value read from the input pin
int currentStateDown = LOW;    // the debounced input value
long timeDown = 0;         // the last time the output pin was sampled
int debounceCountDown = 10; // number of millis/samples to consider before declaring a debounced input

void setup()  { 
  analogReference( INTERNAL2V56_NO_CAP );

  pinMode(SpeedPulsePin, OUTPUT);
  pinMode(TachPulsePin, OUTPUT);

  pinMode(ShiftUpPin, INPUT);
  pinMode(ShiftDownPin, INPUT);
}

void loop()  { 
  int tachPotReading = analogRead(TachPotPin);

  int rpm = tachPotReading * 31.37;
  int rearSpeed = 0;

  if(gear == 1)
    rearSpeed = rpm / 123.2471786256;
  else if(gear == 2)
    rearSpeed = rpm / 73.4626040084;
  else if(gear == 3)
    rearSpeed = rpm / 51.9010740616;
  else if(gear == 4)
    rearSpeed = rpm / 38.9370982081;
  else if(gear == 5)
    rearSpeed = rpm / 31.6846500291;
  else
    rearSpeed = 0;

  long currentTime = millis();

  if(rpm > 0)
  {
    timeBetweenRpmPulses = 60000 / rpm;

    if(timeBetweenRpmPulses > 0 && currentTime - lastTachPulseTime > timeBetweenRpmPulses)
    {
      digitalWrite(TachPulsePin, HIGH);
      lastTachPulseTime = currentTime;
    }
  }

  if(rearSpeed > 0)
  {
    timeBetweenSpeedPulses = 1000 / (rearSpeed * 0.6035454801);

    if(timeBetweenSpeedPulses > 0 && currentTime - lastSpeedPulseTime > timeBetweenSpeedPulses)
    {
      digitalWrite(SpeedPulsePin, HIGH);
      lastSpeedPulseTime = currentTime;
    }
  }

  delay(1);
  digitalWrite(TachPulsePin, LOW);
  digitalWrite(SpeedPulsePin, LOW);

  //ShifterDebounce();
  DebounceAndSetGear();
}

void ShifterDebounce()
{
  if(digitalRead(ShiftUpPin) == HIGH)
  {
    if(lastShiftSelection != WasUp)
      ShiftUp();
    lastShiftSelection == WasUp;
  }
  else if(digitalRead(ShiftDownPin) == HIGH)
  {
    if(lastShiftSelection != WasDown)
      ShiftDown();
    lastShiftSelection == WasDown;
  }
  else
  {
    lastShiftSelection = NoShift;
  }
}

void ShiftUp()
{
  if(gear < 5)
    gear++;
}

void ShiftDown()
{
  if(gear > 0)
    gear--;
}

void DebounceAndSetGear()
{
  boolean up = DebounceUp();
  boolean down = DebounceDown();

  if(up)
    ShiftUp();
  if(down)
    ShiftDown();
}

boolean DebounceUp()
{
  // If we have gone on to the next millisecond
  if(millis() != timeUp)
  {
    readingUp = digitalRead(ShiftUpPin);

    if(readingUp == currentStateUp && counterUp > 0)
    {
      counterUp--;
    }
    if(readingUp != currentStateUp)
    {
      counterUp++; 
    }
    // If the Input has shown the same value for long enough let's switch it
    if(counterUp >= debounceCountUp)
    {
      counterUp = 0;
      currentStateUp = readingUp;
      return true;
    }
    timeUp = millis();
  }
  return false;
}

boolean DebounceDown()
{
  // If we have gone on to the next millisecond
  if(millis() != timeDown)
  {
    readingDown = digitalRead(ShiftDownPin);

    if(readingDown == currentStateDown && counterDown > 0)
    {
      counterDown--;
    }
    if(readingDown != currentStateDown)
    {
      counterDown++; 
    }
    // If the Input has shown the same value for long enough let's switch it
    if(counterDown >= debounceCountDown)
    {
      counterDown = 0;
      currentStateDown = readingDown;
      return true;
    }
    timeDown = millis();
  }
  return false;
}








