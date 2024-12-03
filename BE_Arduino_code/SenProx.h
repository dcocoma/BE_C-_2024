#include <iostream>
#ifndef SENPROX_H
#define SENPROX_H
#include <Arduino.h>

class SenProx {
private:
    int pin;      
    int distance;   

public:
    // Constructor
    SenProx(int pin);
    SenProx(int distance);

   
    void init();

    bool getDistance();

};

#endif


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