#include "database.h"

DataBase::DataBase(){
    this->id=0;

}

QList<DataBaseItem> &DataBase::dataBaseElemetsList(){
    return elemets;
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
