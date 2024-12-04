#include "LCD.h"
#include <Wire.h>
#include "rgb_lcd.h"

LCD::LCD() : colorR(0), colorG(0), colorB(255),PosLCD(0){
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.cursor();
  lcd.blink();
  lcd.print("Hello");
  delay(1000);
}

void LCD::Init() {
  lcd.clear();
  delay(2000);
}

void LCD::SetTextF1(String texto) {
    TextF1 = texto;   
}

void LCD::SetPosLCD(int num) {
    PosLCD = num;    
    lcd.setCursor(PosLCD, 1);  
}

int LCD::getPosLCD() {
  return PosLCD;
}

void LCD::Refresh() {
  uint8_t happy[] = {
  0b00000,  // o 31
  0b11011,  // o 31
  0b11011,  // o 31
  0b00000,  // o 31
  0b10001,  // o 0
  0b01110,  // o 0
  0b00000,  // o 0
  0b00000   // o 0
  };
  uint8_t borrar[] = {
  0b00000,  // o 31
  0b00100,  // o 31
  0b01000,  // o 31
  0b11111,  // o 0
  0b01000,  // o 0
  0b00100,  // o 0
  0b00000,   // o 0
  0b00000
  };
  lcd.clear();           
  lcd.print(String(TextF1));
  lcd.setCursor(0,1);
  lcd.print("0123456789");
  lcd.createChar(2, borrar);
  lcd.createChar(1, happy);
  lcd.setCursor(14, 1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(PosLCD, 1);
}

void LCD::print(String txt){
  lcd.clear();
  lcd.print(txt);
  }

void LCD::setCursor(int pos){
  lcd.setCursor(pos, 1);
}
