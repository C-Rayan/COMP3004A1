#include "catalogue.h"

Catalogue::Catalogue(): itemList() {}

void Catalogue::addItem(const CatalogueItem& item){
    this->itemList.push_back(item);
}

/*void Catalogue::removeItem(const CatalogueItem& item){
    for (c)
    for (CatalogueItem& iter : itemList){
        if (iter.equals(item)){
            itemList.
        }
    }
}*/
