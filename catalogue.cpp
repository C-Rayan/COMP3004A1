#include "catalogue.h"

Catalogue::Catalogue(): itemList() {}

void Catalogue::addItem(const CatalogueItem& item){
    this->itemList.push_back(item);
}

void Catalogue::removeItem(const CatalogueItem& item){
    itemList.erase(std::remove(itemList.begin(), itemList.end(), item), itemList.end());
}
