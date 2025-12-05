#include "system.h"
System::System(): patronList(){
}

// Function used in D1, no corresp implepmentation in D2
void System::addPatron(const Patron& patron){
    this->patronList.push_back(patron);
}

void System::addLibrarian(const Librarian &lib){
    this->librarianList.push_back(lib);
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

Librarian System::getLibrarianAtIndex(int index){
    return librarianList.at(index);
}

bool System::isPatron(int cardNumber){
    for (int i = 0; i < (int) this->patronList.size(); i++){
        if (patronList.at(i).getCardNumber() == cardNumber){
            return true;
        }
    }
    return false;
}
