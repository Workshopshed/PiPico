#include "rtc_api.h"

/* these are not currently covered by the API */
extern "C" 
{
  typedef void(* rtc_callback_t )(void);
  void rtc_set_alarm      (datetime_t *t, rtc_callback_t user_callback);
  void rtc_disable_alarm (void);
  void rtc_enable_alarm (void);
  bool rtc_set_datetime(datetime_t *t);
}

static volatile bool awake;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  // Start the RTC
  rtc_init();

  datetime_t t_start = {
            .year  = 2022,
            .month = 06,
            .day   = 25,
            .dotw  = 6, // 0 is Sunday, so 5 is Friday
            .hour  = 8,
            .min   = 23,
            .sec   = 0  
    };

  //Write initial date
  rtc_set_datetime(&t_start);

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
  rtc_disable_alarm ();
}

static void sleep_callback(void) {
    awake = true;
    return;
}

void loop() {
}