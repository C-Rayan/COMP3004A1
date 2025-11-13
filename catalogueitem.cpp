#include "catalogueitem.h"

CatalogueItem::CatalogueItem(const string& title, const string& author, int publishYear, const string& status, const string& condition, const string& format, int quantity){
    this->title = title;
    this->author = author;
    this->publishYear = publishYear;
    this->status = status;
    this->condition = condition;
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

void CatalogueItem::increaseQuantity(int amount){
    this->quantity = quantity + amount;
}


