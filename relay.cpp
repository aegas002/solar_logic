#include "relay.h"
#include <Arduino.h>
//#include "avr_madness.h"

void Relay::changeState()
{
	if (state == 0)
	{
		state = 1;
		Serial.println("From Off to On ");
	}
	else
	{
		state = 0;
		Serial.println("From On to Off ");
	}
}

void Relay::setPin(int pinn)
{
	pin = pinn;
	pinMode(pin, OUTPUT);
}

int Relay::checkState()
{
	return state;
}

bool Relay::overState()
{
	state = 0;
	digitalWrite(pin, state);
	return true;
}

// void writeAllState(){
// 	digitalWrite(pv.pin, pv.state);
//     digitalWrite(bat.pin, bat.state);
//     digitalWrite(inv.pin, inv.state);

// }
