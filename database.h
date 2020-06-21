#ifndef DATABASE_H
#define DATABASE_H
#include <QList>
#include "databaseitem.h"
#include <QString>
#include <sortingtype.h>


class DataBase{
private:
    QList<DataBaseItem> elemets;
    int id;
    static   bool sortByid(DataBaseItem &item1, DataBaseItem &item2);
    static    bool sortByValue(DataBaseItem &item1, DataBaseItem &item2);

public:
    DataBase();
    QList<DataBaseItem> &dataBaseElemetsList();
    QList<DataBaseItem> dataBaseElemetsSortedList(SortingType &config);
    void addNewItem(QString value);
    void deleteItem(int id);
    ~DataBase();
};

#endif // DATABASE_H
