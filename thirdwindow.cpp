#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "mainwindow.h"
#include "database.h"

#include <QSqlRecord>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

#include <QChartView>
#include <QLineSeries>

#include <QtCharts/QAreaSeries>

ThirdWindow::ThirdWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    plotGraph(); // Вызываем функцию для построения графика
}

void ThirdWindow::plotGraph()
{
    QChart *chart = new QChart();
    chart->setTitle("График измерений");
    QLineSeries *series = new QLineSeries();

    QPen greenPen(Qt::blue); // Создаем перо с зеленым цветом
    series->setPen(greenPen);

    DataBase database;
    QSqlTableModel *model = database.getTableModel();
    int rowCount = model->rowCount();

    for (int i = 0; i < rowCount; ++i) {
        QVariant weightVariant = model->record(i).value("Weight");
        QVariant dateVariant = model->record(i).value("DateOfMeasurement");

        qDebug() << "Weight: " << weightVariant.toDouble();
        qDebug() << "Date: " << dateVariant.toString();

        bool conversionSuccess = false;
        double weight = weightVariant.toDouble(&conversionSuccess);
        if (!conversionSuccess) {
            qDebug() << "Failed to convert weight to double";
            continue;
        }

        QDateTime dateTime = QDateTime::fromString(dateVariant.toString(), "dd.MM.yyyy");

        series->append(dateTime.toMSecsSinceEpoch(), weight);
    }

    chart->addSeries(series);


    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Дата измерения");

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Вес");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->horizontalFrame->addWidget(chartView);
}



ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::on_pushButtonExit3_clicked()
{
    hide();
    MainWindow *window = new MainWindow;
    window->show();
}
