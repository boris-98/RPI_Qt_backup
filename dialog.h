#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "rtc_module.h"
#include <QTimer>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int fd;
    int lcd;
    QString str_time;
    bool form;
    bool position;
    QString alarm_time;

public slots:
    void showTime();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_radioButton_1_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QTimer* myTimer;
};



#endif // DIALOG_H
