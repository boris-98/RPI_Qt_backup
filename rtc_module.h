#ifndef RTC_MODULE_H
#define RTC_MODULE_H

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <QString>
#include <QTime>
#include <iostream>

#include <QDebug>

#define SEK 0x02
#define MIN 0x03
#define SAT 0x04
#define changeHexToInt(hex) ((((hex)>>4) *10 ) + ((hex)%16))
#define DEVICE_ID 0x51

void SetTime(int fd, const unsigned char* g8563_Store);
void InitRTC(int &fd, unsigned char* g8563_Store, const unsigned char* init8563_Store);
void ReadTime(int fd, unsigned char* g8563_Store, QString &str_time, bool form);

#endif // RTC_MODULE_H
