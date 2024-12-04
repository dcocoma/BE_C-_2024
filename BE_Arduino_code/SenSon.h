#include <iostream>
#ifndef SENSON_H
#define SENSON_H
#include <Arduino.h>

class SenSon {
private:
    int pin;      
    int dB;
public:
    // Constructor
    SenSon(int pin);
    int getpin();
    int getDb();
};

#endif