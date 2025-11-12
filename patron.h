#include <vector>
#include <string>
#include "loan.h"
#include <string>

using std::string;

class Patron {
private:
    int curUsers = 0;
    int cardNumber;
    string name;
    string email;
    int currentLoans;
    int pin;
    std::vector<Loan> myLoans;

public:
    Patron(const string& name, const string& email, int pin);
    int getPin();
    std::string getName();
    void ViewAccountStatus();
    int getLoans();
};
