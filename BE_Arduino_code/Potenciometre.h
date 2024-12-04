#ifndef POTENCIOMETRE_H
#define POTENCIOMETRE_H
#include <Arduino.h> 

class Potenciometre {
private:
    int pin; 
    unsigned int pos;
public:
    // Constructor
    Potenciometre();
    int getPosPot(); // Retorna a posição do potenciômetro
};

#endif