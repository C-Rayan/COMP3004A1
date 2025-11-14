#include "system.h"
System::System(): patronList(){
}

void System::addPatron(const Patron& patron){
    this->patronList.push_back(patron);
}

// Simple check to determine whether a card number and pin are correct
int System::systemAuth(const int cardNumber,const int pin){
    // Check if username matches inside of memory database
    for (int i = 0; i < (int) this->patronList.size(); i++){
        if (patronList[i].getCardNumber() == cardNumber && patronList[i].getPin() == pin){
            return i;
        }
    }
    // Non valid username or password
    return -1;
}

Patron System::getPatronAtIndex(int i){
    return patronList.at(i);
}
