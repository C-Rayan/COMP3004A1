#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "patron.h"
#include "catalogue.h"
#include <string>

class System {
public:
    System();
    int systemAuth(const int cardNumber,const int pin);
    void addPatron(const Patron& patron);
    Patron getPatronAtIndex(int index);
    static Catalogue catalogue1;


private:
    std::vector<Patron> patronList;

};


#endif // SYSTEM_H
