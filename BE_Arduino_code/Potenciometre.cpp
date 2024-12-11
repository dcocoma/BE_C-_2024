#include <Arduino.h>
#include "Potenciometre.h"

// Reads the potentiometer position and returns a scaled value
int Potenciometre::getPosPot() {
    pos = analogRead(pin);       // Read the analog value from the pin
    //pos = (1023 - pos);
    pos = (10 * pos) / 1023;     // Scale the value to a range from 0 to 10
    return pos;                  // Return the scaled position
}

