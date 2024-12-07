#ifndef POTENCIOMETRE_H
#define POTENCIOMETRE_H

#include <Arduino.h>

// Class to handle potentiometer operations
class Potenciometre {
private:
    int pin;               // Analog pin connected to the potentiometer
    unsigned int pos;      // Stores the scaled position value

public:
    // Constructor: initializes the potentiometer pin
    Potenciometre();

    // Reads and returns the current potentiometer position
    int getPosPot();
};

#endif