#include "rtc_module.h"

void SetTime(int fd, const unsigned char* g8563_Store) // Ne zaboravi da posaljes i fd
{
    wiringPiI2CWriteReg8(fd, SEK, g8563_Store[0]);
    wiringPiI2CWriteReg8(fd, MIN, g8563_Store[1]);
    wiringPiI2CWriteReg8(fd, SAT, g8563_Store[2]);
}

void InitRTC(int &fd, unsigned char* g8563_Store, const unsigned char* init8563_Store)
{
    unsigned char i;

    fd = wiringPiI2CSetup(DEVICE_ID);
    if(fd == -1)
    {
        std::cout << "Failed to init I2C communication" << std::endl;
    }
    std::cout << "I2C communication successfully setup" << std::endl;

    // Stavljas pocetno vreme
    for(i = 0; i <= 3; i++)
        g8563_Store[i] = init8563_Store[i];

    SetTime(fd, g8563_Store);
    std::cout << "Initial time is setup" << std::endl;

    //inicijalizacija RTC-a
    wiringPiI2CWriteReg8(fd, 0x0, 0x00);
}

void ReadTime(int fd, unsigned char* g8563_Store, QString &str_time, bool form)
{
    unsigned char time[3];

    time[0] = (unsigned char)wiringPiI2CReadReg8(fd, SEK);
    time[1] = (unsigned char)wiringPiI2CReadReg8(fd, MIN);
    time[2] = (unsigned char)wiringPiI2CReadReg8(fd, SAT);

    g8563_Store[0] = time[0] & 0x7f;
    g8563_Store[1] = time[1] & 0x7f;
    g8563_Store[2] = time[2] & 0x3f;

    g8563_Store[0] = changeHexToInt(g8563_Store[0]);
    g8563_Store[1] = changeHexToInt(g8563_Store[1]);
    g8563_Store[2] = changeHexToInt(g8563_Store[2]);


    QTime vreme;
    vreme.setHMS(g8563_Store[2], g8563_Store[1], g8563_Store[0]);
    QString format;
    if(form)
        format = "hh:mm:ss";
    else
        format = "h:m:s a";

    str_time = vreme.toString(format);

    // qDebug() << g8563_Store[2] << " " << g8563_Store[1] << " " << g8563_Store[0] << "\n";
    // qDebug() << str_time << "\n";
}
