#include "catalogueitem.h"

CatalogueItem::CatalogueItem(const string& title, const string& author, int publishYear, const string& condition, const string& format, int quantity){
    this->title = title;
    this->author = author;
    this->publishYear = publishYear;
    this->status = "Unavailable";
    this->condition = condition;
    this->format = format;
    this->quantity = quantity;
    if (quantity > 0){
        this->status = "Available";
    }

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

void CatalogueItem::addToQueue(string name){
    holds.push_back(name);
}

void CatalogueItem::removeFromQueue(string name){
    holds.remove(name);
}

int CatalogueItem::searchQueue(string name){
    int index = -1;
    int cnt =0;
    for(string holder: holds){
        if(holder == name){
            index = cnt;
            break;
        }
        else{
            cnt = cnt+1;
        }
    }
    return index;

}


// Checks if two items are equivalent
bool CatalogueItem::equals(const CatalogueItem& item){
    if (this->author == item.author && this->condition == item.condition &&
        this->format == item.format && this->publishYear == item.publishYear &&
        this->title == item.title && this->status == item.status)
        return true;
    return false;
}

