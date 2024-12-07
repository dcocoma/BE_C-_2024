#ifndef SENPROX_H
#define SENPROX_H

#include <Arduino.h>
#include "Ultrasonic.h"

// Class to handle ultrasonic proximity sensor operations
class SenProx {
private:
    Ultrasonic ultrason; // Object to handle ultrasonic sensor measurements
    int pin;             // Pin connected to the ultrasonic sensor
    int distance;        // Variable to store the measured distance

public:
    // Constructor: initializes the ultrasonic sensor with the specified pin
    SenProx(int pin);

    // Returns the pin number associated with the ultrasonic sensor
    int getpin();

    // Measures and returns the current distance in centimeters
    int getDistance();
};

#endif