#include <iostream>
#ifndef SENSON_H
#define SENSON_H
#include <Arduino.h>

class SenSon {
private:
    int pin;      
    int dB;   
S
public:
    // Constructor
    SenSon(int pin);
    SenSon(int dB);

    void init();

    bool getDb();

};

#endif