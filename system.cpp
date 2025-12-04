#include "system.h"
System::System(): patronList(){
}

void System::addPatron(const Patron& patron){
    this->patronList.push_back(patron);
}

void System::addLibrarian(const Librarian &lib){
    this->librarianList.push_back(lib);
}

// Simple check to determine whether a card number and pin are correct
int System::systemAuth(const int cardNumber,const int pin){
    // Check if username matches inside of memory database and what type of user
    if(isPatron(cardNumber)){
        for (int i = 0; i < (int) this->patronList.size(); i++){
            if (patronList[i].getCardNumber() == cardNumber && patronList[i].getPin() == pin){
                return i;
            }
        }
    }
    else{
        for (int i = 0; i < (int) this->librarianList.size(); i++){
            if (librarianList.at(i).getCardNumber() == cardNumber && librarianList.at(i).getPin() == pin){
                return i;
            }
        }
    }

    // Non valid username or password
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
