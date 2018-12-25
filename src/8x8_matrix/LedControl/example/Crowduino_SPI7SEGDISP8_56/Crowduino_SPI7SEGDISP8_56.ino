#include "LedControl.h"
// Pin 7 to Data In, 6 to Clk, 5 to LOAD
LedControl lc=LedControl(7,6,5,1);
void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,15);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
}
void loop()
{
  for(int i=0; i<8; i++){
   lc.setDigit(0,i,i+1,true);
  }  
  
}
