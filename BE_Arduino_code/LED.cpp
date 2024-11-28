#include <iostream>
#include <Arduino.h>
using namespace std;
class LED {
private:
    int pin;
   
public:
    // Constructor
    LED(int p) : pin(p) {}

    void Init() {
        pinMode(pin, OUTPUT); // set pin as an input
        
    }

    void SetEtat(bool c){
        if (c) {
         digitalWrite(pin, HIGH);
        else{
         digitalWrite(pin, LOW);
         }
};