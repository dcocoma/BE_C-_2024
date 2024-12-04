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

  String TextF1;           
  int PosLCD;

public:
  LCD();
  LCD(const int colorR, const int colorG, const int colorB);  
  void Init();
  void SetTextF1(String texto);
  void SetPosLCD(int num);
  int getPosLCD();
  void Refresh();  
  void print(String txt);
  void setCursor(int pos);
};
#endif
