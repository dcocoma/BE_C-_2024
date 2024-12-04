#ifndef SECURITE_H
#define SECURITE_H

#include <Arduino.h> 
#include "LCD.h"
#include "Button.h"
#include "Potentiometre.h"

class Securite {
private:
    int* motPasse; 
    int* motEcrit;
    int tentatif;
    int posPasse;
    

public:
    // Constructor
     Securite();
    ~Securite();
    // Methods
    bool validation();            
    void effacer(Button &button);  
    void setMotEcrit(int posPot, LCD &lcd, Button &button);
    int PPToPosLCD(int posPot, LCD &lcd);
};

#endifS
