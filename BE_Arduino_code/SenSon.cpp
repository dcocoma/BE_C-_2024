#include <iostream>
#include "SenSon.h"
#include <Arduino.h>
using namespace std;
SenSon::SenSon(int p) : pin(p), dB(0) {}

void SenSon::init() {
    pinMode(pin, INPUT_PULLUP); /
bool SenProx::getDb() {
    dB = analogRead(pin);
    return dB;
}
