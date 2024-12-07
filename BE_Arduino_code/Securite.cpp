#include "Securite.h"  

// Constructor: initializes dynamic arrays and member variables
Securite::Securite() 
    : motEcrit(new int[4]{0, 0, 0, 0}), // Initialize entered password array with zeros
      motPasse(new int[4]{5, 7, 4, 3}), // Set the correct password
      posPasse(0),                      // Start position for entering digits
      tentatif(0),                      // Initial number of attempts
      RightPass(false) {}               // Password validation flag set to false

// Destructor: releases dynamically allocated memory
Securite::~Securite() {
    delete[] motPasse;   // Free memory allocated for the correct password
    delete[] motEcrit;   // Free memory allocated for the entered password
}

// Validates if the entered password matches the correct password
bool Securite::ValiderMotPass() {
    for (int i = 0; i < 4; ++i) {
        if (motPasse[i] != motEcrit[i]) {
            return false; // If any digit doesn't match, return false
        }
    }
    return true; // All digits match, return true
}

// Deletes the last entered digit
void Securite::effacer() {
    if (posPasse > 0) {  // Ensure there's a digit to delete
        posPasse--;      // Move back one position
    }
}

// Sets a digit in the entered password
void Securite::setMotEcrit(int number) {
    motEcrit[posPasse] = number; // Store the digit at the current position
    posPasse++;                  // Move to the next position

    if (posPasse >= 4) { // If all 4 digits have been entered:
        if (ValiderMotPass()) {  // Validate the password
            RightPass = true;    // Mark the password as correct
        }
        posPasse = 0;            // Reset the position for the next entry
        tentatif++;              // Increment the number of attempts
    }
}

// Resets the number of attempts to 0
void Securite::resetTentatives() {
    tentatif = 0; // Reset the attempt counter
}

// Returns the current position in the entered password
int Securite::getPosPasse() {
    return posPasse; // Return the value of posPasse
}

// Returns the current number of attempts
int Securite::getTentatif() {
    return tentatif; // Return the number of attempts
}

// Checks if the password is correct
bool Securite::checkRightPass() {
    return RightPass; // Return the password validation status
}

// Resets the password validation flag
void Securite::ResetRightPass() {
    RightPass = false; // Reset the flag to false
}