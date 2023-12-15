#include "fourthwindow.h"
#include "ui_fourthwindow.h"

FourthWindow::FourthWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FourthWindow)
{
    ui->setupUi(this);
}

FourthWindow::~FourthWindow()
{
    delete ui;
}
