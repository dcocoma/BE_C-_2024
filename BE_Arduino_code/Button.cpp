// Button.cpp
#include <Arduino.h>
#include "Button.h"  // Includes the header file for the Button class

// Returns 'true' if the button is pressed (low), 'false' if not pressed (high)
bool Button::isPressed() {
    return digitalRead(pin);  // Reads the pin state and returns it
}
