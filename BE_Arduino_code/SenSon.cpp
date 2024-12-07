#include <Arduino.h>
#include "SenSon.h"

// Constructor: initializes the sensor pin and default decibel value
SenSon::SenSon(int pin) : pin(pin), dB(0) {
    pinMode(pin, INPUT); // Configure the sensor pin as an input
}

// Returns the pin number associated with the sensor
int SenSon::getpin() {
    return pin; // Return the pin number
}

// Reads and returns the current sound level in decibels (dB)
int SenSon::getDb() {
    dB = analogRead(pin); // Read the analog value from the sensor pin
    return dB;            // Return the decibel value
}

