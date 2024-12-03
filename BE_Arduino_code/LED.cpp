#include <iostream>
#include <Arduino.h>
using namespace std;
#include "LED.h"
LED::LED(int p) : pin(p){}


void LED::init() {
    pinMode(pin, OUTPUT);  //distance by divisor
}

void LED::setEtat(bool c) {
    if (c) {
         digitalWrite(pin, HIGH);
        else{
         digitalWrite(pin, LOW);
         } 
}
};
