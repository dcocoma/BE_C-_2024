#include "LCD.h"
#include <Wire.h>
#include "rgb_lcd.h"

LCD::LCD() : colorR(255), colorG(0), colorB(0),PosLCD(0){
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  //TextF1 = "Welcome";
  lcd.print("hello, world!");
  delay(1000);
}

void LCD::Init() {
  lcd.clear();
  delay(2000);
}

void LCD::SetTextF1(char* texto) {
    TextF1 = texto;   
}

void LCD::SetPosLCD(int num) {
    PosLCD = num;    
    lcd.setCursor(PosLCD, 1);  
}

void LCD::Refresh() {
    lcd.clear();           
    lcd.print(String(TextF1));
    lcd.setCursor(0,1);
    lcd.print("0123456789");
    lcd.setCursor(PosLCD, 1);
}
