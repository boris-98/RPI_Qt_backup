#include "lcd_module.h"

int initLCD()
{
    int lcd;

    if(wiringPiSetup() < 0)
        return -1;

    if(lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4,
                      LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0))
    {
        printf ("lcdInit nije uspeo! \n");
        return -1 ;
    }
    else
        return lcd;
}

void Time2LCD(int lcd,const char* time, bool row) // QString -> to_string() -> cstr(), to_string(Qstr).cstr()
{
    lcdClear(lcd);
    lcdPosition(lcd, 0, row);
    lcdPuts(lcd, time);
}
