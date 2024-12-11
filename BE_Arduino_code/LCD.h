#ifndef LCD_H
#define LCD_H

#include <Wire.h>
#include "rgb_lcd.h"

// Class to handle LCD screen operations
class LCD {
private:
    rgb_lcd lcd;             // LCD object for control
    const int colorR;        // Red component of the backlight color
    const int colorG;        // Green component of the backlight color
    const int colorB;        // Blue component of the backlight color
    String TextF1;           // Text for the first line of the LCD
    String code;
    int PosLCD;              // Cursor position on the second line

public:
    LCD(); // Default constructor
    LCD(const int colorR, const int colorG, const int colorB); // Parameterized constructor

    void Init();             // Initializes the LCD with default settings
    void SetTextF1(String texto); // Sets the text for the first line
    void SetPosLCD(int num); // Sets the cursor position on the second line
    int getPosLCD();         // Gets the current cursor position
    void Refresh();          // Refreshes the LCD with updated content
    void print(String txt);  // Clears the LCD and displays text
    void setCursor(int pos); // Sets the cursor to a specific position
    void setPasscode(int* num);
    String getPasscode();
};

#endif
