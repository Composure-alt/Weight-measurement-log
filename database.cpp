#include "database.h"
#include <QMessageBox>



DataBase::DataBase() {
    // Инициализация базы данных
    bd = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "MyConnectionName"));

    bd->setDatabaseName("./dataBase.bd");

    if (bd->open()) {
        qDebug("Open");
    } else {
        qDebug("No Open");
    }

    model = new QSqlTableModel(nullptr, *bd); // Pass the dereferenced pointer here
    model->setTable("WeightMagazine");

    model->setHeaderData(0, Qt::Horizontal, "Вес");
    model->setHeaderData(1, Qt::Horizontal, "Дата измерения");
    model->select();

    // Инициализация QSqlQuery
    query = new QSqlQuery(*bd); // Pass the dereferenced pointer here
    query->exec("CREATE TABLE IF NOT EXISTS WeightMagazine(Weight TEXT, DateOfMeasurement TEXT)");

}



DataBase::~DataBase() {
    // Остановка работы с базой данных
    bd->close(); // Закрыть соединение
    delete model;
    delete bd; // Удалить соединение
}


void DataBase::inputData(const QString &weight, const QString &dateOfMeasurement)
{
    QString queryString = "INSERT INTO WeightMagazine(Weight, DateOfMeasurement) VALUES (:weight, :dateOfMeasurement)";

    query->prepare(queryString);
    query->bindValue(":weight", weight);
    query->bindValue(":dateOfMeasurement", dateOfMeasurement);

    if(query->exec()) {
        qDebug("Data saved");
        model->select();
        //QMessageBox::information(nullptr, "", "Сохранено");

    } else {
        qDebug("Error: %s", qPrintable(query->lastError().text()));
        //QMessageBox::information(nullptr,"", "Ошибка сохранения");
    }
}

    QSqlTableModel* DataBase::getTableModel()
    {
        return model;
    }


