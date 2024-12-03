#include <iostream>
#include "Buzzer.h"
Button::Button(int p) : pin(p), etat(false), dernierEtat(false) {}

void Buzzer::init() {
    pinMode(pin, OUTPUT); /
void Buzzer::setBuzzer(bool c ) {
    if (c) {
         digitalWrite(pin, HIGH);
        else{
         digitalWrite(pin, LOW);
         }

        }

    }
    
    
