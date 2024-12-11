#include <Arduino.h>
#include "SenProx.h"
#include "Ultrasonic.h"

// Measures and returns the current distance in centimeters
int SenProx::getDistance() {
    int d = ultrason.MeasureInCentimeters(); // Use the Ultrasonic library to measure distance
    // Shift the previous values to the left
    for(int i = 0; i < 5; i++) {
        dfilt[i] = dfilt[i + 1];
    }
    // Add the new value at the end of the array
    dfilt[5] = d;
    // Calculate the average of the last 6 readings
    distance = 0;
    for (int i = 0; i < 6; i++) {
        distance += dfilt[i];
    }
    // Calculate the average
    distance = distance / 6;
    return distance;
}
