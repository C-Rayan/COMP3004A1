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

int CatalogueItem::searchQueue(string name){
    //Looks for the iteraator pointing the specified name
    auto it = find(holds.begin(),holds.end(), name);
    int index =-1;
    if(it != holds.end()){
        index = distance(holds.begin(), it);
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
