#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
private:
    int pin;      
    bool etat;  
    bool dernierEtat; 

public:
    // Constructor
    Button(int pin);

   
    void init();

    bool getButton();

    bool isPressed();
};

#endif
