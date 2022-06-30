# Pi Pico Examples
Pi Pico Examples for Arduino

## RTC
Note that the RTC doesn't initialise until you write a time to it. This can take a few milliseconds so if you read it before it is ready you will get a date of 1970.

Examples of a simple clock and a timer.

https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__rtc.html

## Clock
Some examples of changing the clock speed of the Pico by swapping it to use one of the other clocks or to run at a lower speed.
Note that not all frequencies are available for set_sys_clock_khz. There is a script vcocalc.py which can be used to work out what are valid combinations, copy attached here as it doesn't seem located in the SDK.
A known issue with these is that the USB port and possibly the serial port too won't work after a clock speed change.

## LowPower
The low power example is based on https://github.com/raspberrypi/pico-extras and https://ghubcoder.github.io/posts/awaking-the-pico/ 

## Hardware Reset
This demonstrates how the Pico can do a hardware reset of itself via the Run pin. Attach a wire from GPIO 8 to RUN. The sketch implements a blink where the pico resets every 2 seconds.
