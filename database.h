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
    QList<DataBaseItem> &dataBaseElemetsList();
    QList<DataBaseItem> dataBaseElemetsSortedList(SortingType config);
    void addNewItem(QString value);
    void deleteItem(int id);
    ~DataBase();
};

#endif // DATABASE_H
