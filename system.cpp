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
std::string System::systemAuth(const std::string& name,const int pin){
    // Queries the database to find an equivalent cardNumber and pin
    QSqlQuery query;
    query.prepare("SELECT * FROM PATRONS WHERE card_number = ? AND pin = ?");
    query.addBindValue(QString::fromStdString(name).toInt());
    query.addBindValue(pin);
    if (query.exec()){
        // Gets the user and returns it
        if (query.next()){
            return "Patron";
        }
    }

    QSqlQuery query2;
    query2.prepare("SELECT * FROM LIBRARIANS WHERE name = ? AND pin = ?");
    query2.addBindValue(QString::fromStdString(name));
    query2.addBindValue(pin);
    query2.exec();
    // Gets the user and returns it
    if (query2.next()){
        return "Librarian";
    }

    return "NULL";
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
