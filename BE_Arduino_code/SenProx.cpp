#include <iostream>
#include "SenProx.h"
#include <Arduino.h>
using namespace std;
SenProx::SenProx(int p) : pin(p), distance(0) {}

void SenProx::init() {
    pinMode(pin, INPUT_PULLUP); /
bool SenProx::getDistance() {
    distance = analogRead(pin);
    return distance;
}

