#include "database.h"

DataBase::DataBase(){
    this->id=0;

}

QList<DataBaseItem> DataBase::dataBaseElemets(){
    return elemets;
}


void DataBase::addNewItem(QString value){
    DataBaseItem newItem(value,id);
    elemets.append(newItem);
    id++;
}

DataBase::~DataBase(){

}
