#ifndef CATALOGUE_H
#define CATALOGUE_H
#include "catalogueitem.h"

class Catalogue
{
public:
    Catalogue();
    void addItem(const CatalogueItem& item);
    void removeItem(const CatalogueItem& item);
private:
    std::vector<CatalogueItem> itemList;
};

#endif // CATALOGUE_H
