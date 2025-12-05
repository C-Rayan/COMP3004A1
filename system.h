#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "patron.h"
#include "librarian.h"
#include "catalogue.h"
#include <string>
#include <QSqlQuery>

class System {
public:
    System();
    int systemAuth(const int cardNumber,const int pin);
    void addPatron(const Patron& patron);
    void addLibrarian(const Librarian& lib);
    Patron getPatronAtIndex(int index);
    Librarian  getLibrarianAtIndex(int index);
    bool isPatron(int cardNumber); //assumes each name/username
    static Catalogue catalogue1;


private:
    std::vector<Patron> patronList;
    std::vector<Librarian> librarianList;

};


#endif // SYSTEM_H
