#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "database.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>


SecondWindow::SecondWindow(QWidget *parent, DataBase* dataBase)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
    , dataBase(dataBase)   // Инициализация dataBase в списке инициализации
{
    ui->setupUi(this);

    QSqlTableModel* model = dataBase->getTableModel();
    model->setSort(model->fieldIndex("DateOfMeasurement"), Qt::AscendingOrder);

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet("QTableView { gridline-color: white; }"); // цвет линий
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}


void SecondWindow::on_pushButtonExit2_clicked()
{
    close();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}


void SecondWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        selectedCell = index; // Сохраняем индекс выбранной ячейки
    }
}


void SecondWindow::on_pushButtonDelete2_clicked()
{
    if (selectedCell.isValid()) {
        int row = selectedCell.row();
        int column = selectedCell.column();

        QSqlTableModel* model = dataBase->getTableModel();

        if (model->removeRow(row)) {
            // Удаляем строку из модели
            model->removeRow(row);

            // Обновляем отображение таблицы
            ui->tableView->setModel(model);
            ui->tableView->selectRow(row);  // Выбираем строку для обновления отображения
            ui->tableView->setCurrentIndex(QModelIndex()); // Сбрасываем текущий индекс

            QMessageBox::information(this, "", "Ячейка удалена");
        } else {
            QMessageBox::warning(this, "", "Ошибка удаления ячейки");
        }
    } else {
        QMessageBox::warning(this, "", "Выберите ячейку для удаления");
    }
}

void SecondWindow::on_pushButtonEdit_clicked()
{
    if (selectedCell.isValid()) {
        int row = selectedCell.row();
        int column = selectedCell.column();

        // Получаем новое значение из диалогового окна (например, QLineEdit)
        bool ok;
        QString newValue = QInputDialog::getText(this, tr("Редактировать значение"), tr("Введите новое значение:"), QLineEdit::Normal, "", &ok);
        if (ok && !newValue.isEmpty()) {
            QSqlTableModel* model = dataBase->getTableModel();

            // Устанавливаем новое значение в модель данных
            QModelIndex index = model->index(row, column);
            model->setData(index, newValue);
            model->submitAll(); // Сохраняем изменения в базе данных

            // Явно обновляем представление
            ui->tableView->reset();

            QMessageBox::information(this, "", "Значение ячейки изменено");
        } else {
            QMessageBox::warning(this, "", "Введите корректное значение");
        }
    } else {
        QMessageBox::warning(this, "", "Выберите ячейку для редактирования");
    }
}



