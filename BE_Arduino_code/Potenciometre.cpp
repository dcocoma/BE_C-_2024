#include <Arduino.h>
#include "Potenciometre.h"

Potenciometre::Potenciometre() : pin(A0){
  pinMode(A0,INPUT);
}

int Potenciometre::getPosPot() {
  pos = analogRead(pin);
  return pos;
}

