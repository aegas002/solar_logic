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





// #define AVERAGE_READINGS 30
// struct Sensor{
//   int pin;
//   int total=0;
//   int read[AVERAGE_READINGS];
//   Sensor(){memset(read,0,AVERAGE_READINGS);}
//  // Sensor(int _pin):pin(_pin),Sensor()(_pin){}
// };

// #define NUMB_ANALOGS 3
// int pin_array[] = {A0, A1, A3};
// Sensor sensors[NUMB_ANALOGS];
\
// Set you Offset
int ACSoffset = 600; // See offsets below

/* Offsets
If bi-directional = 2500
If uni- directional = 600
*/

int RawValue = 0;
double Voltage = 0;
double Amps = 0;
int mVperAmp = 40;

#define TIME_S 14
#define P_TIME 3000
//double average = 0;
float currentValue = 0;

float averaged = 0.0f;

int average= 0;
int toAverage = 1550;
float max, min;
float lastAvg = 0.0f;
float initialValue = 0;
unsigned long timer0 = 0, timer1 = 0;


void setup(){
  Serial.begin(115200);
  #ifdef HAS_CURRENT
  pinMode(A0, INPUT_PULLUP);
  #endif


  initialValue = abs(analogRead(A0)); 
}

void loop() {

  if (millis() - timer0 > P_TIME)
  {
    timer0 = millis();
    Serial.println(average - 0.06);
  }

    if (millis() - timer1 > TIME_S)
  {
    RawValue = analogRead(A0);
    Voltage = (abs(RawValue) / 1023.0) * 5000; // Gets you mV
    Amps = ((Voltage - ACSoffset) / mVperAmp);
    average += abs(Amps) * TIME_S / P_TIME;
    timer1 = millis();
  }
  Serial.println("hi");

}
// Below is another implementation of current reading******
// reading = analogRead(A0); //Raw data reading

//   currentValue = abs(reading - initialValue); 

//   if(average >= toAverage){
//   lastAvg = (averaged/toAverage);

  
//   if (send_data(00)){
//       blink(1);
//       delay(5);
//   } else{
//       blink(2, 100, 2);
//   }
//     average = 0;
//     averaged = 0;
    

    
//   } else {
//     averaged += currentValue;
//     average++;
//   delay(1);
//   }
//******************************************************




//void setup(){
//   Serial.begin(115200);
//   pinMode(3, OUTPUT);
//   pinMode(8,OUTPUT);

 // for(int i=0;i<NUMB_ANALOGS;i++){sensors[i] = Sensor(pin_array[i]);}
 //}

// int index=0;
 //void loop(){
    
//     for(int i=0;i<NUMB_ANALOGS;i++){
//       Sensor s=sensors[i];
//       s.read[index] = analogRead(s.pin);
//       s.total = 0;
//       for(int &r:s.read){s.total+=r;}
//       s.total /= AVERAGE_READINGS;
//     }
    
//     if (index++ >= AVERAGE_READINGS)index = 0; // Ups the counter

    




    // Serial.print(" PV Current: " ); 
    // Serial.print(sensors[0].total);
    // Serial.print("  Charging Current: ");
    // Serial.print(sensors[1].total);
    // Serial.print("  Invertor Current: ");
    // Serial.println(sensors[2].total);
    // delay(100);




  //     digitalWrite(3, HIGH);
  //      digitalWrite(8, HIGH);    // turn the LED on (HIGH is the voltage level)
  //    delay(1000);                       // wait for a second
  // digitalWrite(3, LOW); 
  //  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  // delay(1000); 


//       total= total - readings[index];          
//     readings[index] = analogRead(0); //Raw data reading
//     readings[index] = (readings[index]-510)*5/1024/0.04-0.
// 04;//Data processing:510-
// raw data from analogRead when the input is 0; 5-5v; the first
//  0.04-
// 0.04V/A(sensitivity); the second 0.04-offset val;
//     total= total + readings[index];       
//     index = index + 1;                    
//     if (index >= numReadings)              
//       index = 0;                           
//     average = total/numReadings;   //Smoothing algorithm 
// (http://www.arduino.cc/en/Tutorial/Smoothing)    
//     currentValue= average;
//     Serial.println(currentValue);
//     delay(100);
//}
