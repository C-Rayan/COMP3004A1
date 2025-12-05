#include "catalogue.h"

Catalogue::Catalogue(): itemList() {}

void Catalogue::addItem(const CatalogueItem& item){
    this->itemList.push_back(item);
}

void Catalogue::removeItem(const CatalogueItem& item){
    itemList.erase(std::remove(itemList.begin(), itemList.end(), item), itemList.end());

}

CatalogueItem Catalogue::findItem(const int uid){
    for (int i = 0; i < this->getItemList().size(); i++){
        if (this->getItemList().at(i).getCID() == uid){
            return this->getItemList().at(i);
    }
}
}
