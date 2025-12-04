#include "librarian.h"

Librarian::Librarian(const string name, const string email, Catalogue& c, int card, int pass): name(name), email(email), catalogue(c), cardNumber(card), passwrd(pass){
    string sql = "SELECT name, email, pin FROM PATRON";
    //[code to add database stuff to clients]
}

Patron Librarian::findPatron(string name){
    for(Patron p: clients){
        if(p.getName() == name){
            return p;
        }
    }
    return Patron();
}

void Librarian::addItem(CatalogueItem item){
    catalogue.addItem(item);
}

void Librarian::removeItem(CatalogueItem item){
    catalogue.removeItem(item);
}

void Librarian::returnForPatron(Patron client, CatalogueItem item){
    client.removeLoan(item);
}

