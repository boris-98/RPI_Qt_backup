#include "yl_40.h"

YL_40::YL_40()
{
    yl_40 = ADDRESS;
}

bool YL_40::InitYL()
{
	if(wiringPiSetup() == -1)
		return false;
	
	fd = wiringPiI2CSetup(yl_40);
	return true;
}

int YL_40::get_fd() const
{
	return fd;
}

int YL_40::get_ADCval(int pin)
{
	ADCval = wiringPiI2CReadReg8(fd, yl_40 + pin);
	return ADCval; 
}
