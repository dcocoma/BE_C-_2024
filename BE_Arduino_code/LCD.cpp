#include <iostream>
#include "LCD.h"

LCD::LCD(int rs, int enable, int d4, int d5, int d6, int d7) : lcd(rs, enable, d4, d5, d6, d7) {
    // Construtor da classe LCD, inicializa o LCD com os pinos fornecidos
}

void LCD::Init() {
    lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
    lcd.clear();       // Limpa a tela ao iniciar
}

void LCD::SetTextF1(char* texto) {
    TextF1 = texto;   // Define o texto a ser exibido no LCD
}

void LCD::SetPosLCD(int num) {
    PosLCD = num;     // Define a posição do cursor (coluna 0 a 15)
    lcd.setCursor(PosLCD, 0);  // Move o cursor para a posição dada
}

void LCD::Refresh() {
    lcd.clear();           // Limpa o display
    lcd.print(TextF1);     // Exibe o texto no LCD
}
