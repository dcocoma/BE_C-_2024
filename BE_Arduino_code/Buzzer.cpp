#include <iostream>
#include <Arduino.h>
using namespace std;
class Buzzer {
private:
    int pin; 
public:
    // Constructor
    Buzzer(int p) : pin(p), distance(0) {}

    void Init() {
        pinMode(pin, OUTPUT); // set pin as an output
        
    }
    void SetBuzzer(bool c){
        if (c) {
         digitalWrite(pin, HIGH);
        else{
         digitalWrite(pin, LOW);
         }

        }
    }
};