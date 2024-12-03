#include <iostream>
#include <Arduino.h> 
using namespace std;
#ifndef LED_H
#define LED_H
class LED {
private:
    int pin; 

public:
    // Constructor
    LED(int p);

    // Methods
    void init();             // Inicializa o potenciômetro
    void setEtat(); // Retorna a posição do potenciômetro
};

#endif