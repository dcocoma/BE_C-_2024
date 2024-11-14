#include "Ultrasonic.h"

Ultrasonic ultrasonic(D7);

void setup() {
  // put your setup code here, to run once:
  // pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  //delay(1000);                      // Wait for a second
  //digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  //delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
  long RangeInCentimeters;

  //Serial.println("The distance to obstacles in front is: ");

  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.println(RangeInCentimeters);//0~400cm
  //Serial.println(" cm");
  delay(250);
}
