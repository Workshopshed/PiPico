# Pi Pico Examples
Pi Pico Examples for Arduino

## RTC
Note that the RTC doesn't initialise until you write a time to it. This can take a few milliseconds so if you read it before it is ready you will get a date of 1970.

A simple clock and a timer.
https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__rtc.html

## Clock
Some examples of changing the clock speed of the Pico by swapping it to use one of the other clocks or to run at a lower speed.