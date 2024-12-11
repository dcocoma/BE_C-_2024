// Button.h
#ifndef BUTTON_H  // Preprocessor directive to prevent multiple inclusions
#define BUTTON_H  // Defines the header guard to avoid multiple inclusions

#include <Arduino.h>  // Includes the main Arduino library to use functions like pinMode, digitalRead
#include "Component.h"
// Declaration of the Button class
class Button : public Component{
public:
    // Constructor that takes a pin number as an argument and sets it up
    Button(int pin) : Component(pin) { pinMode(pin, INPUT_PULLUP); }  
    
    // Method that returns 'true' if the button is pressed
    bool isPressed();  
};

#endif  // End of the header guard to prevent multiple inclusions
