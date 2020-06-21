#include "sortingtype.h"


SortingType::SortingType(){

}

SortingType::SortingType(int type, int order){
    this->type=type;
    this->order=order;
}

int SortingType::sortingType(){
    return type;
}

int SortingType::sortingOrder(){
    return order;
}
