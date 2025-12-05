#ifndef CATALOGUE_H
#define CATALOGUE_H
#include "catalogueitem.h"
#include <vector>

class Catalogue
{
public:
    Catalogue();
    void addItem(const CatalogueItem& item);
    void removeItem(const CatalogueItem& item);
    std::vector<CatalogueItem> getItemList() {return itemList;}
    CatalogueItem findItem(const int uid);
private:
    std::vector<CatalogueItem> itemList;
};

#endif // CATALOGUE_H
