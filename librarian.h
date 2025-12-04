#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "patron.h"
#include "catalogue.h"
//#include <sqlite3.h>

using namespace std;

class Librarian{

private:
    string name;
    string email;
    int print;
    Catalogue& catalogue;
    //sqlite3* db;
    string dbName;
    list<Patron> clients;



public:
    Librarian(const string name, const string email, Catalogue& c, const string dbName);
    //Getters
    const string getName(){return name;}
    const string getEmail(){return email;}
    int getPrint(){return print;}
    Catalogue& getCatalogue(){return catalogue;}
    list<Patron> getClients(){return clients;}

    Patron findPatron(string name);
    void returnForPatron(Patron client, CatalogueItem item);
    void addItem(CatalogueItem item);
    void removeItem(CatalogueItem item);



};

#endif // LIBRARIAN_H
