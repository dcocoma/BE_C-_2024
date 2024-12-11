#include <Arduino.h>
#include "SenSon.h"

// Reads and returns the current sound level in decibels (dB)
int SenSon::getDb() {
    dB = analogRead(pin); // Read the analog value from the sensor pin
    return dB;            // Return the decibel value
}

