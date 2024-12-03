#include "Securite.h"
#include "LCD.h"
#include "Button.h"
#include "Potentiometre.h"

Securite::Securite() : motEcrit(new int[4]{0, 0, 0, 0}), motPasse(new int[4]{5, 7, 4, 3}), posPasse(0), tentatif(0) {}

bool Securite::validation() {
    for (int i = 0; i < 4; i++) {
        if (motPasse[i] != motEcrit[i]) {
            tentatif++;
            if (tentatif >= 3) {
                return false;
            }
            return false;
        }
    }
    tentatif = 0;
    return true;
}

void Securite::effacer(Button &button) {
    static unsigned long startPressTime = 0;

    if (button.isPressed()) {
        if (startPressTime == 0) {
            startPressTime = millis();
        } else if (millis() - startPressTime >= 3000) {
            if (posPasse > 0) {
                posPasse--;
                motEcrit[posPasse] = 0;
            }
            startPressTime = 0;
        }
    } else {
        startPressTime = 0;
    }
}

void Securite::setMotEcrit(int posPot, LCD &lcd, Button &button) {
    
    int numero = PPToPosLCD(posPot, lcd);

    // Verify if the button was pressed
    if (button.getButton()) {
        motEcrit[posPasse] = numero;         
        posPasse = (posPasse + 1) % 4;      
    }
}


void Securite::PPToPosLCD(int posPot, LCD &lcd, Button &button) {
    int numero = map(posPot, 0, 1023, 0, 9);

    lcd.SetPosLCD(posPasse);
    lcd.SetTextF1(String(numero).c_str());
    lcd.Refresh();

    if (button.getButton()) {
        motEcrit[posPasse] = numero;
        posPasse = (posPasse + 1) % 4;
    }
}
