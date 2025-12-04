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
    int passwrd;
    int cardNumber;
    Catalogue& catalogue;
    //sqlite3* db;
    //string dbName;
    list<Patron> clients;



public:
    Librarian(const string name, const string email, Catalogue& c,int card, int pass);
    //Librarian(const string name, const string email, int card, int pass);
    // Prevent copying (because catalogue ref cannot be reseated)
    //Getters
    const string getName(){return name;}
    const string getEmail(){return email;}
    int getPin(){return passwrd;}
    int getCardNumber(){return cardNumber;}

    void setCatalogue(Catalogue& c){ catalogue = c;}

    Catalogue& getCatalogue(){return catalogue;}
    list<Patron> getClients(){return clients;}

    Patron findPatron(string name);
    void returnForPatron(Patron client, CatalogueItem item);
    void addItem(CatalogueItem item);
    void removeItem(CatalogueItem item);



};

#endif // LIBRARIAN_H
