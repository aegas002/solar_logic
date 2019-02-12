//Class for reading senors that are on the pv system
#ifndef SENSOR
#define SENSOR

#define AVERAGE_READINGS 30
struct Sensor{
  int pin;
  float total=0;
  float read[AVERAGE_READINGS];
  //Sensor(){memset(read,0,AVERAGE_READINGS);}
 // Sensor(int _pin):pin(_pin),Sensor()(_pin){}
  float monitor(Sensor first);
  float monitorAll(Sensor first, Sensor second, Sensor thrird);
  void print();
}sensepv,sensebat,senseinv;

#endif SENSOR
