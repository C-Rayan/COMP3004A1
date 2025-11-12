#include "system.h"
System::System(): patronList(){
}

void System::addPatron(const Patron& patron){
    this->patronList.push_back(patron);
}

bool System::systemAuth(const std::string& name, int pin){
    // Check if username matches inside of memory database
    for (int i = 0; i < (int) this->patronList.size(); i++){
        if (patronList[i].getName() == name && patronList[i].getPin() == pin){
            return true;
        }
    }
    // Non valid username or password
    return false;
}
