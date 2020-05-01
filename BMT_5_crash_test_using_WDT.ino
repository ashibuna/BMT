#include <avr/wdt.h>
 
void setup()
{
  Serial.begin(9600);
 // wdt_enable(WDTO_1S);
}
 
void loop()
{
  // the program is alive...for now. 
  //wdt_reset();
 
  Serial.println("Hello");
 
  while (1)
    ; // do nothing. the program will lockup here. 
 
  Serial.println("Can't get here");
}
