#ifndef LOAN_H
#define LOAN_H

#include "catalogueitem.h"
#include <string>
#include <ctime>

class Loan : public CatalogueItem{

public:
    Loan(const CatalogueItem& item, tm date);

    int getRemainingDays() const;
    CatalogueItem getItem() const;
    tm getDueDate() ;


private:
    tm dueDate;
    CatalogueItem item;
};


#endif // LOAN_H
