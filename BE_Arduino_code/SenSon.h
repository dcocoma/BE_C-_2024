#ifndef SENSON_H
#define SENSON_H

#include <Arduino.h>

// Class to handle sound sensor operations
class SenSon {
private:
    int pin; // Pin connected to the sound sensor
    int dB;  // Variable to store the current decibel value

public:
    // Constructor: initializes the sensor with the specified pin
    SenSon(int pin);

    // Returns the pin number associated with the sensor
    int getpin();

    // Reads and returns the current sound level in decibels
    int getDb();
};

#endif