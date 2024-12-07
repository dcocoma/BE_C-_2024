#include <Arduino.h>
#include "Potenciometre.h"

// Constructor: initializes the potentiometer pin
Potenciometre::Potenciometre() : pin(A0) {
    pinMode(A0, INPUT); // Configure the pin as an input
}

// Reads the potentiometer position and returns a scaled value
int Potenciometre::getPosPot() {
    pos = analogRead(pin);       // Read the analog value from the pin
    pos = (10 * pos) / 1023;     // Scale the value to a range from 0 to 10
    return pos;                  // Return the scaled position
}

