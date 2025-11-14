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
