#include <string>
#include "Patron.h"

int Patron::curUsers = 0;
Patron::Patron(const string& name, const string& email, int pin){
    this->cardNumber = ++curUsers;
    this->name = name;
    this->email = email;
    this->pin = pin;
}

// Used to force QT's default parameters in some functions, is not used however
Patron::Patron(){
    name = "empty";
    email = "empty";
    pin = 438984913;
}

int Patron::getPin(){
    return pin;
}

std::string Patron::getName(){
    return name;
}

// Adds loan only if user has less than 3 and item is available
bool Patron::addLoan(const Loan& loan){
    if (numLoans >= 3 || loan.getItem().getStatus() == "Unavailable"){
        return false;
    }
    this->myLoans.push_back(loan);
    numLoans++;
    loan.getItem().reduceQuantity(1);
    loan.getItem().setStatus("Unavailable");
    return true;
}

int Patron::getLoansSize(){
    return this->myLoans.size();
}


std::vector<Loan> Patron::getLoans(){
    return myLoans;
}

std::vector<CatalogueItem> Patron::getHoldList(){
    return myHolds;
}

int Patron::getCardNumber(){
    return cardNumber;
}

void Patron::addHold(const CatalogueItem& hold){
    this->myHolds.push_back(hold);
}

// Method with implemented equals in CatalogueItem that checks all attributes
Loan* Patron::getLoanForItem(const CatalogueItem& item){
    for (int i = 0; i < myLoans.size(); i++){
        if (myLoans.at(i).getItem().equals(item)){
            return &myLoans.at(i);
        }
    }
    return nullptr;
}

// Removes a loan from a patron loans list
void Patron::removeLoan(const CatalogueItem& item){
    if (myLoans.size() < 0){
        return;
    }
    std::cout << myLoans.size();
    Loan* selectLoan = getLoanForItem(item);
    const Loan& selectedLoan = *selectLoan;
    // Goes thru the whole vector to find all* (only 1) specific loan and delete it
    this->myLoans.erase(std::remove(myLoans.begin(), myLoans.end(), selectedLoan), myLoans.end());
    numLoans--;
    selectedLoan.getItem().increaseQuantity(1);
    selectedLoan.getItem().setStatus("Available");
}

// Removes a hold from a patron hold list
void Patron::removeHold(const CatalogueItem& item){
    if (myHolds.size() < 0){
        return;
    }
    // Goes thru the whole vector to find all* (only 1) specific hold and delete it
    myHolds.erase(std::remove(myHolds.begin(), myHolds.end(), item), myHolds.end());
    //also remove holds from item list
}
