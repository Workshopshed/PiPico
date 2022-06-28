#include "Clock48Mhz.h"

void setup() {

  //Swap the system clock to run from the USB clock source and turn off Sys PLL
  //Standard clode speed is  133MHz.
  set_sys_clock_48mhz();

  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // Delay is now taking longer should still blink at 1s intervals. Need to work out where this is driven from
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);        
}
