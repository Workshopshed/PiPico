#include "rtc_api.h"
#include <TimeLib.h> //https://github.com/PaulStoffregen/Time

char datetime_buf[256];
char *datetime_str = &datetime_buf[0];
tmElements_t tm;
time_t t;

void setup() {
  tm.Year  = CalendarYrToTm(2022);
  tm.Month = 06;
  tm.Day   = 25;
  tm.Wday  = 6; // 0 is Sunday, so 6 is Saturday
  tm.Hour  = 8;
  tm.Minute   = 23;
  tm.Second   = 00;

  t = makeTime(tm);
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  sleep_ms(5000);

  // Start the RTC
  Serial.println("Initialising RTC");
  rtc_init();

  //Write initial date
  rtc_write(t);

  while(!rtc_isenabled()) 
  { Serial.print(".");}
  Serial.println("");

  Serial.println("RTC Running");
}

void loop() {
  t = rtc_read();

  Serial.print(year(t));
  Serial.print("-");
  Serial.print(month(t));
  Serial.print("-");
  Serial.print(day(t));
  Serial.print(" ");
  Serial.print(hour(t));
  Serial.print(":");
  Serial.print(minute(t));
  Serial.print(":");
  Serial.println(second(t));
  Serial.println();
  sleep_ms(1000);
}