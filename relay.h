//This is the header file for the relays
//Sensor input is needed to evalute relay state. 
//Current relay state can be know ny uncommenting the outputs from the code below
#ifndef RELAY
#define RELAY

struct Relay{

int state = 0; //state LOW (0) off, state ON(1) on 
int pin; 

void changeState(Relay relay);
int checkState(Relay relay);
bool startState(Relay first, int pinFirst, Relay second, int pinSecond, Relay third, int pinThird);
bool maintState(Relay first, Relay second, Relay third);
bool overState(Relay relay); //Sets relays off if overcurrent is detected
//void writeAllState();
}; 
#endif