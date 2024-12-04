#include <Arduino.h>
#include "SenSon.h"

SenSon::SenSon(int pin) : pin(pin), dB(0) {
  pinMode(pin, INPUT);
}

int SenSon::getpin() {
    return pin;
}
int SenSon::getDb() {
  dB = analogRead(pin);
  return dB;
}
