#ifndef YL_40_H
#define YL_40_H

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#define ADDRESS 0x48

class YL_40
{
    public:

        YL_40();
        int get_fd() const;
        int get_ADCval(int pin);
        bool InitYL();

    private:

        int fd;
        int ADCval;
        char yl_40;
};

#endif // YL_40_H
