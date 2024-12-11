// Component.cpp
#include <Arduino.h>
#include "Component.h"  // Includes the header file for the Button class


    Component::Component(int pin) : pin(pin){};  
    
    void Component::setPin(int pin){ this->pin = pin; }
    
    int Component::getPin(){ return pin; }