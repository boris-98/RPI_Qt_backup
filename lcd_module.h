#ifndef LCD_MODULE_H
#define LCD_MODULE_H

#include <wiringPi.h>
#include <lcd.h>
#include <iostream>

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6

int initLCD();
void Time2LCD(int lcd,const char* time, bool row);


#endif // LCD_MODULE_H
