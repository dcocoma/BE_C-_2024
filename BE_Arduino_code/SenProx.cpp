#include <iostream>
#include <Arduino.h>
using namespace std;
class SenProx {
private:
    int pin;
    int distance; 

public:
    // Constructor
    SenProx(int p) : pin(p), distance(0) {}

    void Init() {
        pinMode(pin, INPUT); // set pin as an input
        
    }

    int getDistance() {
        distance = analogRead(pin);
        return distance;
    }
};

// main arduino

//SensProx sensor(2); // Sensor conectado no pino 2

//void setup() {
//    Serial.begin(9600);
//   sensor.Init(); // Inicializa o sensor
//}

//void loop() {
//    int dist = sensor.getDistance();
//   Serial.println("Distância: " + String(dist));
//    delay(1000);
//}