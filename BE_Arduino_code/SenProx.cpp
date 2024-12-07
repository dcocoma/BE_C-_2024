#include <Arduino.h>
#include "SenProx.h"
#include "Ultrasonic.h"

// Constructor: initializes the ultrasonic sensor with the specified pin
SenProx::SenProx(int pin) 
    : ultrason(pin),  // Initialize the Ultrasonic object with the provided pin
      pin(pin),       // Store the pin number
      distance(0) {}  // Initialize the distance to 0

// Returns the pin number associated with the ultrasonic sensor
int SenProx::getpin() {
    return pin;
}

// Measures and returns the current distance in centimeters
int SenProx::getDistance() {
    distance = ultrason.MeasureInCentimeters(); // Use the Ultrasonic library to measure distance
    return distance;                            // Return the measured distance
}
