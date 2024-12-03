#include <iostream>
using namespace std;
#ifndef SECURITE_H
#define SECURITE_H
#include <Arduino.h> 
class Securite {
private:
    int* motPasse; 
    int* motEcrit;
    int tentatif;
    int posPasse;
    

public:
    // Constructor
     Securite(int* motPasse, int maxTentatif);
    ~Securite();
    // Methods
    bool validation(int* motPasse, int* motEcrit);            
    void effacer();  
    void setMotEcrit(int posPasse, int motLCD);
    int PPToPosLCD(int posPot);
};

#endif