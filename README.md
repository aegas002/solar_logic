# solar_logic
## Logical code for portable solar generator (nano, uno, SAMN board, etc..)

Before starting make sure you have the correct operating system in use. I listed a recommended compliers to use depending on what operating system you are using.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

**Linux:**
If using linux download this makefile from my friend: (PROS - use your own text editor of your choice)
https://github.com/rubend056/arduino_make_template 

Just rename my project whatever you want and save it under the src folder. Then read the makefile for compiling instructions.

***You can use this makefile for all your arduino projects***
HOW?
1) Save all your arduino projects as seperate folders under the src folder. EX -> flash_project
2) When flashing your project to your arduino you can just specify what project to build. Ex -> PRJ:flash_project 
3) Read the makefile for more parameter options. Beats ArduinoIDE out the water!
***If you have issues or trouble please do not hesitate to email me***


**Windows:**
If using Windows you must use the ArduinoIDE:

In order to use the ArduinoIDE with this project you must download the common folder from:
https://github.com/rubend056/arduino_make_template  
and place it in the Arduino->Libraries folder. 
***You should update the board.txt file if you are using an AVR programmer***


**MAC:**
Use above windows method

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Get the project running: 

My project (AS OF NOW) is only reading sensors and displaying them. Testing is in progress to get accurate sensor readings. If you like to see my hardware wiring, sensors i am using, and/or communcation architecture please email me. I will share you with where im at.

***Will update soon LAST UPDATE: 05/07/2019***


