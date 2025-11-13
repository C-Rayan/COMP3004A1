#include <string>
#include "Patron.h"

Patron::Patron(const string& name, const string& email, int pin){
    this->cardNumber = curUsers++;
    this->name = name;
    this->email = email;
    this->pin = pin;
}

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
    if (numLoans >= 3){
        return false;
    }
    this->myLoans.push_back(loan);
    numLoans++;
    addLoanSuccess = true;
    return true;
}

bool Patron::getLoanSuccess(){
    return addLoanSuccess;
}

int Patron::getLoansSize(){
    return this->myLoans.size();
}





