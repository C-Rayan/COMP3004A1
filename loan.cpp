#include "loan.h"

Loan::Loan(const CatalogueItem& item, tm date): dueDate(date), item(item){
    dueDate.tm_mday += 14; // due date is always 14 days from intial checkout
    mktime(&dueDate);
}

int Loan::getRemainingDays() const{
    time_t now = time(NULL);
    tm temp = dueDate;
    time_t due = mktime(&temp);
    double timediff = difftime(due, now);
    int daysRemaining = static_cast<int>(timediff / (60 * 60 * 24)); // convert seconds → days
    return daysRemaining;
}

CatalogueItem Loan::getItem() const{
    return item;
}

tm Loan::getDueDate(){
    return dueDate;
}
