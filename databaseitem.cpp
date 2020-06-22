#include "databaseitem.h"

DataBaseItem::DataBaseItem(){
    this->status=0;
    this->value=nullptr;
    this->id=-1;
}

DataBaseItem::DataBaseItem(QString value, int id){
    this->status=1;
    this->value=value;
    this->id=id;
}


void DataBaseItem::changeStatus(){
    status=!status;
}

QString DataBaseItem::itemValue(){
    return value;
}

int DataBaseItem::ItemId(){
    return id;
}

void DataBaseItem::changeValue(QString newValue)
{
    this->value=newValue;
}

bool DataBaseItem::itemStatus(){
    return status;
}
