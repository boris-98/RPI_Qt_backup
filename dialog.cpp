#include "dialog.h"
#include "ui_dialog.h"
#include "rtc_module.h"
#include "lcd_module.h"
#include <QString>
#include <string>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(showTime()));
    myTimer->start(500);
    form = false;
    position = false;
    pinMode(25, OUTPUT);
    digitalWrite(25, 0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showTime()
{
    unsigned char store[3];
    ReadTime(fd, store, str_time, form);
    // qDebug() << str_time << "\n";
    ui->label_3->setText(str_time);

    std::string str = str_time.toStdString();
    const char* Cstr = str.c_str();

    // qDebug() << Cstr << "\n";

    Time2LCD(lcd, Cstr, position);
    qDebug() << str_time << "\n";
    std::string std_str = str_time.toStdString();
    std_str = std_str.substr(0, 9);

    if(std_str == alarm_time.toStdString())
    {
        qDebug() << "Ukljuci se vise\n";
        digitalWrite(25, 1);
    }

    qDebug() << alarm_time << "\n";
}

void Dialog::on_pushButton_clicked()
{
    QString str;
    unsigned char rtc_time[3];
    int h, m, s;
    str = ui->lineEdit->text();
    std::string temp_str = str.toStdString();
    std::string val;

    // 12:01:12
    val = temp_str.substr(0, 2);
    h = std::stoi(val);
    rtc_time[2] = (unsigned char)h;

    val = temp_str.substr(3, 2);
    m = std::stoi(val);
    rtc_time[1] = (unsigned char)m;

    val = temp_str.substr(6, 2);
    s = std::stoi(val);
    rtc_time[0] = (unsigned char)s;

    // qDebug() << rtc_time[2] << " " << rtc_time[1] << " " << rtc_time[0] << "\n";

    SetTime(fd, rtc_time);
}

void Dialog::on_checkBox_toggled(bool checked)
{
    position = checked;
}

void Dialog::on_radioButton_1_clicked(bool checked)
{
    if(checked == true)
        form = true;
}

void Dialog::on_radioButton_2_clicked(bool checked)
{
    if(checked == true)
        form = false;
}

void Dialog::on_pushButton_2_clicked()
{
    alarm_time = ui->lineEdit_2->text();
    digitalWrite(25, 0);
}
