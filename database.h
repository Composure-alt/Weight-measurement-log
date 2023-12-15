#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

class DataBase
{
private:

    QSqlTableModel* model;
    QSqlQuery* query;
    QSqlDatabase* bd;


public:
    DataBase();
    ~DataBase();

    void inputData(const QString& weight, const QString& dateOfMeasurement);
    QSqlTableModel* getTableModel();

};



#endif // DATABASE_H
