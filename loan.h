#ifndef LOAN_H
#define LOAN_H

#include "catalogueitem.h"
#include <string>
#include <ctime>

class Loan : public CatalogueItem{

public:
    // compares addresses and remove its same addresss
    bool operator==(const Loan& check) const{
        return &this->item == &check.item;
    }
    Loan(const CatalogueItem& item, tm date);

    int getRemainingDays() const;
    CatalogueItem getItem() const;
    tm getDueDate() ;


private:
    tm dueDate;
    CatalogueItem item;
};


#endif // LOAN_H
