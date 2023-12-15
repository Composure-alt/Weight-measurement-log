#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_EnterData_clicked();

    void on_Exit_clicked();

    void on_outputTable_clicked();

    void on_OutputAGraph_clicked();

private:

    Ui::MainWindow *ui;
    DataBase* dataBase;
};
#endif // MAINWINDOW_H
