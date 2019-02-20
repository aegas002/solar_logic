#include "sensor.h"
#include <Arduino.h>
#include <stdio.h>
#include <string.h>

float Sensor::monitor(){
 //initialValue = abs(analogRead(A0));
  if (millis() - timer0 > P_TIME)
  {
    timer0 = millis();
    Serial.println(average - 0.06);
  }

  if (millis() - timer1 > TIME_S) //respond rate of sensor
  {
    RawValue = analogRead(pin);
    Voltage = (abs(RawValue) / 1023.0) * 5000; // Gets you mV
    Amps = ((Voltage - offset) / mVperAmp);
    average += abs(Amps) * TIME_S / P_TIME;
    timer1 = millis();
  }
}

void Sensor::setPin(int _pin){
	pin = _pin;
	pinMode(pin, INPUT_PULLUP);
	// delay(10);
}

void Sensor::setCurrentPin(int _pin, char value){
    pin = _pin;
	  pinMode(pin, INPUT_PULLUP);
   (value == 'a')?offset=UNIoffset:offset=BIoffset;
}

void Sensor::init(){
	memset(read,0,AVERAGE_READINGS*sizeof(typeof(read[0])));
}

void Sensor::print(){
	
}