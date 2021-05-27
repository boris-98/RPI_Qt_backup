#include "dialog.h"
#include <QApplication>
#include "lcd_module.h"

int main(int argc, char *argv[])
{
    int fd;
    unsigned char g8563_Store[3];
    unsigned char init8563_Store[3] = {0x00, 0x00, 0x00};
    InitRTC(fd, g8563_Store, init8563_Store);

    int lcd;
    lcd = initLCD();

    QApplication a(argc, argv);
    Dialog w;
    w.fd = fd;
    w.lcd = lcd;
    w.show();

    return a.exec();
}
