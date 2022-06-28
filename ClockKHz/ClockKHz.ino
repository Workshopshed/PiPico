#include "ClockKHz.h"

void setup() {
  set_sys_clock_khz(10000,true);  //10MHz

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Delay is now taking longer should still blink at 1s intervals. Need to work out where this is driven from
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);        
}
