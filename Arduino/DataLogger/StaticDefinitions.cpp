#include "CarData.h"
int CarData::rpmOverSpeed = 0;
int CarData::RearSpeed = 0;
int CarData::Rpm = 0;
int CarData::Gear = 0;
float CarData::XG = 0.0;
float CarData::YG = 0.0;
float CarData::ZG = 0.0;
boolean CarData::Stationary = true;
boolean CarData::Braking = true;
int CarData::LastDistanceTravelled = 0;

#include "Settings.h"
int Settings::LaunchRpm = 5500;
int Settings::LaunchRpmTolerance = 122;
int Settings::ShiftRpm = 6800;

#include "Logger.h"
unsigned long Logger::logTime = 0;
unsigned long Logger::startTime = 0;
boolean Logger::Logging = false;

#include "HighScores.h"
boolean HighScores::lastStationary = true;
unsigned long HighScores::sessionStartTime = 0;
float HighScores::top60 = 999.99; // low positive
float HighScores::live60 = 999.99;
float HighScores::top100 = 999.99; // low positive
float HighScores::live100 = 999.99;
float HighScores::top400m = 999.99; // low positive
float HighScores::live400m = 999.99;
int HighScores::topSpeed = 0; // high positive
int HighScores::liveSpeed = 0;
float HighScores::topNSG = 0.00; // Z - high positive
float HighScores::liveNSG = 0.00;
float HighScores::topEWG = 0.00; // Y - high modulus
float HighScores::liveEWG = 0.00;

