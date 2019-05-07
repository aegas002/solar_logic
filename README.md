# solar_logic
## Logical code for portable solar generator (nano, uno, SAMN board, etc..)

Before starting make sure you have the correct operating system in use. I listed a recommended compliers to use depending on what operating system you are using.

If you have your desired text editor or Ardunio IDE you can skip this next step

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

**Linux:**
If you are using linux I suggest downloading this makefile for the Arduino: 
https://github.com/rubend056/arduino_make_template . Just save the folder under the src folder and read the makefile for compiling instructions. Easy!

**Windows:**
If using Windows you must use the ArduinoIDE or any text editor of your choice.
In order to use the ArduinoIDE with this project you must download the common folder and place it 
in the Arduino->Libraries folder. You should update the board.txt file if you are using the AVR programmer

**MAC:**
Use above windows method

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Get the project running: 
To see the the hardware line diagram for the project please ask for persmission to view the project folder:
Hardware Items are soley consisted of Current Sensors and Voltage Sensors

Clone the project into a folder name of your choice

If using custom makefile: 
  simple type "make" to build and "flash" to flash code to microcontroller

If using Arduino IDE:
  you will need to copy all code in main.cpp into the arduino main file.


