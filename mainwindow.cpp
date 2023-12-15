#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firstwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataBase = new DataBase();


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_EnterData_clicked()
{
    hide();
    FirstWindow *window = new FirstWindow;
    window->show();
}


void MainWindow::on_Exit_clicked()
{
    close();
}


void MainWindow::on_outputTable_clicked() {
    hide();
    SecondWindow *window = new SecondWindow(nullptr, dataBase);
    window->show();
}



void MainWindow::on_OutputAGraph_clicked()
{
    hide();
    ThirdWindow *window = new ThirdWindow;
    window->show();
}

