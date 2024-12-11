#ifndef SECURITE_H
#define SECURITE_H
#include <Arduino.h>
#include "LCD.h"
class Securite {
private:
    int* motPasse;      // Pointer to store the correct password (4 digits)
    int* motEcrit;      // Pointer to store the entered password (4 digits)
    int tentatif;       // Counter for the number of attempts
    int posPasse;       // Current position in the entered password
    bool RightPass;

public:
    // Constructor and Destructor
    Securite(LCD* lcd);         // Initializes the password and attempts counter
    ~Securite();        // Releases dynamically allocated memory

    // Methods
    bool ValiderMotPass();     // Validates if the entered password matches the correct password
    void effacer();            // Deletes the last entered digit
    void setMotEcrit(int number); // Sets a digit in the entered password
    void resetTentatives();    // Resets the number of attempts to 0
    int getPosPasse();         // Returns the current position in the entered password
    int getTentatif();         // Returns the current number of attempts
    int* getMotEcrit();
    bool checkRightPass();
    void ResetRightPass();
    LCD* lcd;
};

#endif