#include "system.h"
System::System(): patronList(){
}

// Function used in D1, no corresp implepmentation in D2
void System::addPatron(const Patron& patron){
    this->patronList.push_back(patron);
}

// Simple check to determine whether a card number and pin are correct
int System::systemAuth(const int cardNumber,const int pin){
    // Queries the database to find an equivalent cardNumber and pin
    QSqlQuery query;
    query.prepare("SELECT * FROM PATRONS WHERE card_number = ? AND pin = ?");
    query.addBindValue(cardNumber);
    query.addBindValue(pin);
    if (query.exec()){
        // Gets the user and returns it
        if (query.next()){
            return query.value("card_number").toInt();
        }
    }
    return -1;
}

Patron System::getPatronAtIndex(int i){
    return patronList.at(i);
}
