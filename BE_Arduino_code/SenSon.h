#ifndef SENSON_H
#define SENSON_H

#include <Arduino.h>
#include "Component.h"

// Class to handle sound sensor operations
class SenSon : public Component{
private:
    int pin; // Pin connected to the sound sensor
    int dB;  // Variable to store the current decibel value

public:
    // Constructor: initializes the sensor with the specified pin
    SenSon(int pin) : Component(pin){
      pinMode(pin, INPUT);
      dB = 0;
    }
    // Reads and returns the current sound level in decibels
    int getDb();
};

#endif