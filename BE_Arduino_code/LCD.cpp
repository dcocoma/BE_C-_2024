#include <iostream>
#include "LCD.h"

LCD::LCD(int rs, int enable, int d4, int d5, int d6, int d7) : lcd(rs, enable, d4, d5, d6, d7) {
   
}

void LCD::init() {
    lcd.begin(16, 2);  
    lcd.clear();       
}

void LCD::setTextF1(char* texto) {
    TextF1 = texto;   
}

void LCD::setPosLCD(int num) {
    PosLCD = num;    
    lcd.setCursor(PosLCD, 0);  
}

void LCD::refresh() {
    lcd.clear();           
    lcd.print(TextF1);    
}
