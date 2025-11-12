#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "patron.h"
#include "catalogue.h"
#include <string>

class System {
public:
    System();
    bool systemAuth(const std::string& name, int pin);
    void addPatron(const Patron& patron);



private:
    std::vector<Patron> patronList;
    static Catalogue catalogue1;

};


#endif // SYSTEM_H
