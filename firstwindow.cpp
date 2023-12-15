#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

#include "database.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
    , dataBase()
{
    ui->setupUi(this);

}


FirstWindow::~FirstWindow()
{
    delete ui;
}

void FirstWindow::on_Back_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void FirstWindow::on_SaveData_clicked()
{

    QString weightText = ui->weightLineEdit->text();
    QString userInput = ui->DataLineEdit->text();

    bool weightIsNumber;
    double weight = weightText.toDouble(&weightIsNumber);

    // проверка на вводимые значения

    if (!weightIsNumber || weight < 0) {
        QMessageBox::warning(this, "", "Пожалуйста, введите действительное положительное число для веса.");
        return;
    }

    QDate currentDate = QDate::currentDate();
    QDate inputDate = QDate::fromString(userInput, "dd.MM.yyyy");

    if (!inputDate.isValid() || inputDate > currentDate) {
        QMessageBox::warning(this, "", "Пожалуйста, введите действительную дату в формате дд.мм.гггг.");
        return;
    }
    // Вывод сообщения на русском
    QMessageBox::information(this, "", "Данные успешно сохранены");

    dataBase.inputData(weightText, userInput); // Используем член класса database


    ui->weightLineEdit->clear();
    ui->DataLineEdit->clear();


}
