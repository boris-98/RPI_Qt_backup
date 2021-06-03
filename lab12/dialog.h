#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "yl_40.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void showChart();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QTimer* myTimer;
    QtCharts::QLineSeries *series;
    bool startChart;
    int cnt;
    YL_40 device;
    bool flag;
    QtCharts::QChart *chart;
};

#endif // DIALOG_H
