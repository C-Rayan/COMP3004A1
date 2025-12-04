#include "librarian.h"

Librarian::Librarian(const string name, const string email, Catalogue& c, const string dbName): name(name), email(email), catalogue(c), dbName(dbName){
    string sql = "SELECT name, email, pin FROM PATRON";
    //[code to add database stuff to clients]
}

Patron Librarian::findPatron(string name){

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
