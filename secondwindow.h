#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit SecondWindow(QWidget *parent = nullptr, DataBase* dataBase = nullptr);
    ~SecondWindow();

 private slots:
     void on_pushButtonExit2_clicked();

     void on_tableView_clicked(const QModelIndex &index);

     void on_pushButtonDelete2_clicked();

     void on_pushButtonEdit_clicked();

 private:
    Ui::SecondWindow *ui;

    DataBase* dataBase;

    QModelIndex selectedCell;

};

#endif // SECONDWINDOW_H
