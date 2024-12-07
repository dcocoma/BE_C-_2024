// Button.cpp
#include <Arduino.h>
#include "Button.h"  // Includes the header file for the Button class


// Constructor for the Button class, which takes the pin number as an argument
Button::Button(int pin) : pin(pin) {
  pinMode(pin, INPUT_PULLUP);  // Configures the pin as an input with an internal pull-up resistor
}

// Method that returns whether the button is pressed
// Returns 'true' if the button is pressed (low), 'false' if not pressed (high)
bool Button::isPressed() {
    return digitalRead(pin);  // Reads the pin state and returns it
}
