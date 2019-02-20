//Class for reading senors that are on the pv system
#include <Arduino.h>

#ifndef SENSOR
#define SENSOR
#define TIME_S 14
#define P_TIME 3000
#define AVERAGE_READINGS 30

struct Sensor
{
  int RawValue = 0;
  double Voltage = 0;
  double Amps = 0;
  int mVperAmp = 40;
  int average = 0;
  unsigned long timer0 = 0, timer1 = 0;
  // Set your Offset
  int offset = 0;
  int BIoffset = 2500; // reminder
  int UNIoffset = 600; // See offsets below
  /* Offsets
  If bi-directional = 2500
  If uni- directional = 600
  */

  int pin;
  float total = 0.0f;
  float read[AVERAGE_READINGS];
  void setPin(int pin);
  void setCurrentPin(int pin, char value);
  float monitor();
  void print();
  Sensor() : Sensor(A5)
  {
    //#pragma message("Using default pin :/")
  }
  Sensor(int _pin, char offset)
  {
    init();
    setCurrentPin(_pin, offset);
  }
  Sensor(int _pin)
  {
    init();
    setPin(_pin);
  }

private:
  void init();
};

#endif
