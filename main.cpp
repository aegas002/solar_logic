#include "avr_madness.h"
#include "relay.h"

// //*************************** To use Arduino main
// #include "arduino_main.h"
// // Bsic blink sketch with LED connected to PIND bit 5, or pin 5 in the arduino
// void setup(){
// 	SET_DDR(D,5); // Will set DDRD, bit 5 as output
// }
// void loop(){
// 	delay(1000);
// 	SET_PORT(D,5);
// 	delay(1000);
// 	CLR_PORT(D,5);
// }



//*************************** To use your own main
#include <avr/io.h>
#include <util/delay.h>

#include <Arduino.h>


// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	
	init();

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

const int numMax = 30;
float sensor0[numMax];
float sensor1[numMax];
float sensor2[numMax];     // the reading from the analog input
int index = 0;                  // the index of the current reading
float total0, total1, total2 = 0;              // the running total
float Value0 , Value1, Value2 = 0;

void setup(){
	Serial.begin(115200);
    pinMode(3, OUTPUT);
    pinMode(8,OUTPUT);
    for (int Read = 0; Read < numMax; Read++){
        sensor0[Read] = 0;
        sensor1[Read] = 0;
        sensor2[Read] = 0;  
        }
}

void loop(){
    total0 = total0 - sensor0[index];
    total1 = total1 - sensor1[index]; 
    total2 = total2 - sensor2[index];          
    sensor0[index] = analogRead(0); 
    sensor1[index] = analogRead(3);
    sensor2[index] = analogRead(6);
    sensor0[index] = (sensor0[index]-512)*5/1024/0.04+0.22; 
    sensor1[index] = (sensor1[index]-512)*5/1024/0.04+0.22; 
    sensor2[index] = (sensor2[index]-512)*5/1024/0.04+0.22;                                                     
    total0 = total0 + sensor0[index];  
    total1 = total1 + sensor1[index]; 
    total2 = total2 + sensor2[index];


    index = index + 1;
    if (index >= numMax)              
      index = 0;                           
    Value0 = total0/numMax; 
    Value1 = total1/numMax;
    Value2 = total2/numMax; 
    Serial.println(" ");
    Serial.print(" PV Current: " ); 
    Serial.print(Value0);
    Serial.print("  Charging Current: ");
    Serial.print(Value1);
    Serial.print("  Invertor Current: ");
    Serial.print(Value2);
    delay(100);
  //     digitalWrite(3, HIGH);
  //      digitalWrite(8, HIGH);    // turn the LED on (HIGH is the voltage level)
  //    delay(1000);                       // wait for a second
  // digitalWrite(3, LOW); 
  //  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  // delay(1000); 
}
