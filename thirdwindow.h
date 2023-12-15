#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

    void plotGraph();

private slots:
    void on_pushButtonExit3_clicked();

private:
    Ui::ThirdWindow *ui;

};

#endif // THIRDWINDOW_H
