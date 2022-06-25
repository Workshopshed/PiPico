#include "rtc_api.h"
#include <TimeLib.h> //https://github.com/PaulStoffregen/Time

/* these are not currently covered by the API */
extern "C" 
{
  typedef void(* rtc_callback_t )(void);
  void rtc_set_alarm      (datetime_t *t, rtc_callback_t user_callback);
}

char datetime_buf[256];
char *datetime_str = &datetime_buf[0];
tmElements_t tm;
time_t t;

static volatile bool awake;

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

  // Start the RTC
  rtc_init();

  //Write initial date
  rtc_write(t);

  while(!rtc_isenabled()) 
  { }

datetime_t t_alarm = {
            .year  = 2022,
            .month = 06,
            .day   = 25,
            .dotw  = 6, // 0 is Sunday, so 5 is Friday
            .hour  = 8,
            .min   = 23,
            .sec   = 30   //30s later than the initial time
    };

  Serial.println("Waiting for alarm");

  rtc_set_alarm(&t_alarm,&sleep_callback);

  while(!awake) {}

  Serial.print("Woken Up");
}

static void sleep_callback(void) {
    awake = true;
    return;
}

void loop() {
}