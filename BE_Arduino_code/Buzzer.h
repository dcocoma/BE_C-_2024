#include <iostream>
#ifndef BUZZER_H
#define BUZZER_H
#include <Arduino.h>

class Buzzer {
private:
    int pin;      
     

public:
    // Constructor
    Buzzer(int pin);

   
    void init();

    void setBuzzer(bool c);

   
};

#endif
};