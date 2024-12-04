#include <iostream>
#ifndef SENPROX_H
#define SENPROX_H
#include <Arduino.h>
#include "Ultrasonic.h"

class SenProx {
private:
    Ultrasonic ultrason;
    int pin;
    int distance;   

public:
    // Constructor
    SenProx(int pin);
    int getpin();
    int getDistance();
};

#endif