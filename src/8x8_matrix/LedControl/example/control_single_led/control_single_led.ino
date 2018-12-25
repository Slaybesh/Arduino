//This code below will turn on every dot of the matrix to test that all LEDs work. 
#include "LedControl.h" 
#include "binary.h" 
/* 
 ***** These pin numbers are for the Atmega328P 
 * with Uno bootloader ***** 
 * LedControl (name)=LedControl(DataIn,CLK,LOAD,number of Max7219) * 
 * pin 12 is connected to the DataIn to first cluster of 8 
 * pin 11 is connected to the CLK 
 * pin 10 is connected to LOAD 
 * number 1-8 up to 8 matricies 
 * 
 */ 
LedControl lc0=LedControl(12,11,10,1); 
void setup(){ 
 //we have already set the number of devices when we created the LedControl 
 int deviceA=lc0.getDeviceCount(); 
 //we have to init all devices in a loop 
 for(int addressA=0;addressA<deviceA;addressA++) 
 { 
 /*The MAX72XX is in power-saving mode on startup*/ 
 lc0.shutdown(addressA,false); 
 /* Set the brightness to a medium value (1-15) */ 
 lc0.setIntensity(addressA,15); 
 /* and clear the display */ 
 lc0.clearDisplay(addressA); 
 } 
} 
/* To determine which LEDs will be on, think of the row as having 8 positions with a specific number attached to each 
(128, 64, 32, 16, 8, 4, 2, 1) 
If you want every other dot ON in the row starting with the first, add the numbers located in the position you want ON. 
(128 + 0 + 32 + 0 + 8 + 0 + 2 + 0) = 170. Use the number 170 in place of 255 below to turn on every other. 
All the LEDs on in the row would be (128 + 64 + 32 + 16 + 8 + 4 + 2 + 1) = 255. 
*/ 
void loop(){ 
 //switch the led in the third row (index 2) eighth column (index 7) on
lc0.setLed(0,2,7,true);   
delay(500);
lc0.setLed(0,2,7,false);  
delay(500);
}

