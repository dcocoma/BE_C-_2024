#include <Arduino.h>
#include "SenProx.h"
#include "Ultrasonic.h"

// Constructor
SenProx::SenProx(int pin) 
    : ultrason(pin),  // Initialize the Ultrasonic member with the given pin
      pin(pin),
      distance(0) {}

// Getter for the pin
int SenProx::getpin() {
    return pin;
}

// Getter for the distance
int SenProx::getDistance() {
    distance = ultrason.MeasureInCentimeters();
    return distance;
}
