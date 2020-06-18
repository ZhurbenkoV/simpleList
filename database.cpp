#include "database.h"

DataBase::DataBase(){
    this->id=0;

}

QList<DataBaseItem> &DataBase::dataBaseElemetsList(){
    return elemets;
}

QList<DataBaseItem> DataBase::dataBaseElemetsSortedList(SortingType config){
    QList<DataBaseItem> sortedElements;
    //TODO Добавить реализацию метода
    return sortedElements;
}


void DataBase::addNewItem(QString value){
    DataBaseItem newItem(value,id);
    elemets.append(newItem);
    id++;
}

void DataBase::deleteItem(int id)
{
    elemets.takeAt(id);
}

DataBase::~DataBase(){

}
