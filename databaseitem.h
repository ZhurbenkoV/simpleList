#ifndef DATABASEITEM_H
#define DATABASEITEM_H
#include <QString>

class DataBaseItem{

private:
QString value;
int id;
bool status;

public:
    DataBaseItem();
    DataBaseItem(QString value,int id);
    void changeStatus();
    QString itemValue();
    int ItemId();
};

#endif // DATABASEITEM_H
