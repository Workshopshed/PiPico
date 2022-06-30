void setup() {
  //Attach a wire from GPIO 8 to RUN
  pinMode(8,INPUT_PULLUP);
 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    

  //Reset  
  pinMode(8,OUTPUT);
  digitalWrite(8, LOW);   
}

void loop() {
}
