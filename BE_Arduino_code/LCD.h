#ifndef LCD_H
#define LCD_H
#include <Wire.h>
#include "rgb_lcd.h"

class LCD {
private:
  rgb_lcd lcd;

  const int colorR;
  const int colorG;
  const int colorB;      

  char* TextF1;           
  int PosLCD;

public:
  LCD();
  LCD(const int colorR, const int colorG, const int colorB);  
  void Init();
  void SetTextF1(char* texto);  
  void SetPosLCD(int num);      
  void Refresh();  
};
#endif
