#ifndef POTENCIOMETRE_H
#define POTENCIOMETRE_H

#include <Arduino.h>
#include "Component.h"
// Class to handle potentiometer operations
class Potenciometre : public Component{
private:
    unsigned int pos;      // Stores the scaled position value

public:
    // Constructor: initializes the potentiometer pin
    Potenciometre() : Component(A0){
      pinMode(pin, INPUT_PULLUP);
    };

    // Reads and returns the current potentiometer position
    int getPosPot();
};

#endif