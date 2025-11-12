#include "CatalogueItem.h"


CatalogueItem::CatalogueItem(const string& title, const string& author, int publishYear, const string& status, const string& condition, const string& format, int quantity) : holds(){
    this->title = title;
    this->author = author;
    this->publishYear = publishYear;
    this->status = status;
    this->condtion = condition;
    this->format = format;
    this->quantity = quantity;
}

void CatalogueItem::reduceQuantity(int amount){
    if (this->quantity - amount >= 0){
        this->quantity = (this->quantity) - amount;
    }
    else{
        std::cout << "The quantity cannot reduce below 0" << std::endl;
    }
}


bool CatalogueItem::equals(const CatalogueItem& item){
    if (this->title == item.title
      && this->author == item.author
        && this->publishYear == item.publishYear
        && this->condtion == item.condtion
        && this->format == item.format)
        return true;
    return false;
}

void CatalogueItem::increaseQuantity(int amount){
    this->quantity = quantity + amount;
}


