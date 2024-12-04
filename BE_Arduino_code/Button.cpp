#include <iostream>
#include "Button.h"
using namespace std;
Button::Button(int p) : pin(p), etat(false), dernierEtat(false) {
  pinMode(pin, INPUT_PULLUP);
}
bool Button::isPressed() {
    return  digitalRead(pin);
}
