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
    int pin;
    std::vector<Loan> myLoans;
    std::vector<CatalogueItem> myHolds;
    int numLoans = 0;
    bool addLoanSuccess = false;

public:
    Patron(const string& name, const string& email, int pin);

    // Used to create an empty patron (Whose values will be stored later)
    Patron();
    int getPin();
    std::string getName();
    void ViewAccountStatus();
    int getLoansSize();
    void addLoan(const Loan& loan);
    bool getLoanSuccess();
    std::vector<Loan> getLoans();
    std::vector<CatalogueItem> getHoldList();

};
