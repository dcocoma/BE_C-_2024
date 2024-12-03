#include <iostream>
#include "Button.h"
using namespace std;
Button::Button(int p) : pin(p), etat(false), dernierEtat(false) {}

void Button::init() {
    pinMode(pin, INPUT_PULLUP); /
bool Button::getButton() {
    
    bool estatActuel = !digitalRead(pin); 
    
    if (etatActuel && !dernierEtat) {
        dernierEtat = etatActuel; 
        return true;              /
    }
    
    dernierEtat = estatActuel;
    return false; 
}

bool Button::isPressed() {
    return !digitalRead(pin);
}
