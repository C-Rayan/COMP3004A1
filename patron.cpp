#include <string>
#include "Patron.h"

Patron::Patron( const string& name, const string& email, int pin){
    this->cardNumber = curUsers++;
    this->name = name;
    this->email = email;
    this->currentLoans = 0;
    this->pin = pin;
}

int Patron::getPin(){
    return pin;
}

std::string Patron::getName(){
    return name;
}





