#include <iostream>
#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "Component.h"

class Buzzer : public Component{
public:
    // Constructor
    Buzzer(int pin):Component(pin){
      pinMode(pin, OUTPUT);
    }

    void setBuzzerON();
    void setBuzzerOFF();
};
#endif