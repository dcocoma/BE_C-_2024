// Button.h
#ifndef COMPONENT_H  // Preprocessor directive to prevent multiple inclusions
#define COMPONENT_H  // Defines the header guard to avoid multiple inclusions

#include <Arduino.h>  // Includes the main Arduino library to use functions like pinMode, digitalRead

// Declaration of the Button class
class Component {

protected:
    int pin;  // Private attribute to store the pin number to which the button is connected

public:
    // Constructor that takes a pin number as an argument and sets it up
    Component(int pin);  

    void setPin(int pin);
    
    int getPin();
};

#endif  // End of the header guard to prevent multiple inclusions