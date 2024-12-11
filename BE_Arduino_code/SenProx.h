#ifndef SENPROX_H
#define SENPROX_H

#include <Arduino.h>
#include "Ultrasonic.h"
#include "Component.h"

// Class to handle ultrasonic proximity sensor operations
class SenProx : Component{
private:
    Ultrasonic ultrason; // Object to handle ultrasonic sensor measurements
    int distance;        // Variable to store the measured distance
    int* dfilt;

public:
    // Constructor: initializes the ultrasonic sensor with the specified pin
    SenProx(int pin) : Component(pin), ultrason(pin),  // Initialize the Ultrasonic object with the provided pin
    dfilt(new int[5]{0, 0, 0, 0, 0}),
    distance(0) {}  // Initialize the distance to 0
    // Measures and returns the current distance in centimeters
    int getDistance();
};

#endif