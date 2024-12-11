#include "Buzzer.h"

// Turn the buzzer on
void Buzzer::setBuzzerON() {
  digitalWrite(pin, HIGH);
}

// Turn the buzzer off
void Buzzer::setBuzzerOFF() {
  digitalWrite(pin, LOW);
}
