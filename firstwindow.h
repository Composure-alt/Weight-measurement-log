#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QMessageBox>
#include <fstream>
#include "database.h"

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private slots:
    void on_Back_clicked();
    void on_SaveData_clicked();

private:
    Ui::FirstWindow *ui;
    DataBase dataBase; // Перемещаем сюда
};

#endif // FIRSTWINDOW_H
