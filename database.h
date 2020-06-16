#ifndef DATABASE_H
#define DATABASE_H
#include <QList>
#include "databaseitem.h"
#include <QString>


class DataBase{
private:
    QList<DataBaseItem> elemets;
    int id;

public:
    DataBase();
    QList<DataBaseItem> DataBaseElemets();
    int globalID();
    void addNewItem(int id,QString value);
    ~DataBase();
};

#endif // DATABASE_H
