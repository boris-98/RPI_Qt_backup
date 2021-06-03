#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    device()
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(showChart()));
    myTimer->start(1000);
    startChart = false;
    flag = false;

    series = new QLineSeries();

    // konfiguracija grafika...
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisX()->setMin(0);
    chart->axisX()->setMax(6);
    chart->axisY()->setRange(0, 3.3);
    chart->setTitle("Napon na potenciometru");

    // qDebug() << "Stigao sam ovde" << "\n";
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView);

    cnt = 0;
    device.InitYL();
    // qDebug() << "Stigao sam do kraja konstruktora" << "\n";

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showChart()
{
    int adcVal;
    double voltage;
    const double resolution = 3.3 / 256.0;

    if(!startChart)
    {
        series->clear();
        cnt = 0;
    }
    else
    {
        if(cnt == 6)
        {
            cnt = 0;
            series->clear();
        }
        else
        {
            adcVal = device.get_ADCval(3);
            voltage = (double)adcVal * resolution;
            qDebug() << "Napon je: " << voltage << "\n";
            series->append(cnt, voltage);
            // chart->addSeries(series);
            cnt++;
        }
    }

}

void Dialog::on_pushButton_1_clicked()
{
    startChart = false;
}

void Dialog::on_pushButton_2_clicked()
{
    startChart = true;
}
