#include "relay.h"
#include <Arduino.h>
//#include "avr_madness.h"


  
void Relay::changeState(Relay x){
	 if(x.state == 0){
	 	x.state = 1;
	 	Serial.println("From Off to On ");
	 }
	 else{
	 	x.state = 0;
	 	Serial.println("From On to Off ");
	 }
}

bool Relay::startState(Relay pv, int pvpin, Relay bat, int batpin, Relay inv, int invpin){
	//try{
	pv.pin = pvpin;
	bat.pin = batpin;
	inv.pin = invpin;
	delay(10);
	pinMode(pvpin, OUTPUT);
	pinMode(batpin, OUTPUT);
	pinMode(invpin,OUTPUT);
	pv.state = LOW;   
	bat.state = HIGH; //Battery must be connected first for mppt power up. Order goes battery, Pv , and Load(INV)   
	inv.state = LOW;
	delay(10);
	digitalWrite(pv.pin, pv.state);
    digitalWrite(bat.pin, bat.state);
    digitalWrite(inv.pin, inv.state);
	// }catch(std::exception){
	// 	Serial.println("Error setting up pins");
	// 	return false;
	// }
	return true;
}

int Relay::checkState(Relay x){
	return x.state;
}

bool Relay::maintState(Relay pv, Relay bat, Relay inv){
	pv.state = LOW;
	bat.state = LOW;
	inv.state = LOW;
	delay(10);
	digitalWrite(pv.pin, pv.state);
    digitalWrite(bat.pin, bat.state);
    digitalWrite(inv.pin, inv.state);
	return true;
}

bool overState(Relay x){
	x.state = LOW;
	delay(10);
	digitalWrite(x.pin, x.state);
}

// void writeAllState(){
// 	digitalWrite(pv.pin, pv.state);
//     digitalWrite(bat.pin, bat.state);
//     digitalWrite(inv.pin, inv.state);

// }
