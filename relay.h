//This is the header file for the relays
//Sensor input is needed to evalute relay state. 
//Current relay state can be know ny uncommenting the outputs from the code below
#ifndef RELAY
#define RELAY

class relay{
int relay0State, relay1State, relay2State = 0; //state 0 off, state 1 on 
const int relay0 = 3;
const int relay1 = 6;
const int relay2 = 8;

void *changeState(int relay, float a);
int checkState( int relay);
bool *startState(); 
bool *maintState();
bool *overState( int relay); //Sets relays off if overcurrent is detected
};

#endif