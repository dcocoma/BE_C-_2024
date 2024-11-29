#include <iostream>
#include <Arduino.h>
using namespace std;
class Potenciometre {
private:
    int pin;
    int position; 

public:
    // Constructor
    Potenciometre(int p) : pin(p), position(0) {}

    void Init() {
        pinMode(pin, INPUT); // set pin as an input
        
    }

    int getPosPot() {
        position = analogRead(pin);
        return position;
    }
};


