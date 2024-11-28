#include <iostream>
#include <Arduino.h>
using namespace std;
class Button {
private:
    int pin;
    bool etat; 

public:
    // Constructor
    Button(int p) : pin(p), etat(0) {}

    void Init() {
        pinMode(pin, INPUT); // set pin as an input
        
    }

    bool getEtat() {
        etat = analogRead(pin);
        return etat;
    }
};