#include "database.h"

bool DataBase::sortByid(DataBaseItem &item1, DataBaseItem &item2){
    if(item1.ItemId()<item2.ItemId()){
        return true;
    }
    else{
        return false;
    }
}

bool DataBase::sortByValue(DataBaseItem &item1, DataBaseItem &item2){
    return QString::compare(item1.itemValue(),item2.itemValue(),Qt::CaseInsensitive)<0;
}

DataBase::DataBase(){
    this->id=0;

}

QList<DataBaseItem> &DataBase::dataBaseElemetsList(){
    return elemets;
}

QList<DataBaseItem> DataBase::dataBaseElemetsSortedList(SortingType &config){
    QList<DataBaseItem> sortedElements=this->elemets;
    switch (config.sortingType()) {
    case 0:
        foreach(DataBaseItem str,sortedElements){
            std::sort(sortedElements.begin(),sortedElements.end(),sortByid);
        }
        break;
    case 1:
        std::sort(sortedElements.begin(),sortedElements.end(),sortByValue);
        break;
    default:
        break;
    }
    if(config.sortingOrder()==1){
        for(int i=0;i<sortedElements.size()/2;i++){
            sortedElements.swapItemsAt(i,sortedElements.size()-(1+i));
        }
    }
    return sortedElements;
}


void DataBase::addNewItem(QString value){
    DataBaseItem newItem(value,id);
    elemets.append(newItem);
    id++;
}

void DataBase::deleteItem(int id){
    elemets.removeAt(id);
}

DataBase::~DataBase(){

}
