#include <iostream>
#include <Arduino.h>
using namespace std;
class SenSon {
private:
    int pin;
    int dB; 

public:
    // Constructor
    SenSon(int p) : pin(p), dB(0) {}

    void Init() {
        pinMode(pin, INPUT); // set pin as an input
        
    }

    int getdB() {
        dB = analogRead(pin);
        return dB;
    }
};