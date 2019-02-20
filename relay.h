#include "Arduino.h"

//This is the header file for the relays
#ifndef RELAY
#define RELAY

struct Relay{

int state = 0; //state LOW (0) off, state ON(1) on 
int pin; 

void setPin(int pin);
void changeState();
int checkState();
bool overState(); 
//void writeAllState();
Relay():Relay(0){
    //insert erro message if defualt contruct is called
}
Relay(int _pin){
    setPin(_pin);
}
private:
    void init();
}; 
#endif