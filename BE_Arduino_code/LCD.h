#ifndef LCD_H
#define LCD_H
#include <LiquidCrystal.h>  

class LCD {
private:
    LiquidCrystal lcd;      
    char* TextF1;           
    int PosLCD;             

public:
    LCD(int rs, int enable, int d4, int d5, int d6, int d7);  
    void Init();   
    void SetTextF1(char* texto);  
    void SetPosLCD(int num);      
    void Refresh();  

#endif
