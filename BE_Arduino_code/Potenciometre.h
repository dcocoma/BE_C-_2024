#include <iostream>
using namespace std;
#ifndef POTENCIOMETRE_H
#define POTENCIOMETRE_H
#include <Arduino.h> 
class Potenciometre {
private:
    int pin; 

public:
    // Constructor
    Potenciometre(int p);

    // Methods
    void init();             // Inicializa o potenciômetro
    unsigned int getPosPot(); // Retorna a posição do potenciômetro
};

#endif