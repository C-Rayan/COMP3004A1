#include <vector>
#include <string>
#include "loan.h"
#include <string>

using std::string;

class Patron {
private:
    int cardNumber;
    static int curUsers;
    string name;
    string email;
    int pin;
    std::vector<Loan> myLoans;
    std::vector<CatalogueItem> myHolds;
    int numLoans = 0;

public:
    Patron(const string& name, const string& email, int pin);

    // Used to create an empty patron (Whose values will be stored later)
    Patron();
    int getPin();
    std::string getName();
    void ViewAccountStatus();
    int getLoansSize();
    bool addLoan(const Loan& loan);
    bool getLoanSuccess();
    std::vector<Loan> getLoans();
    std::vector<CatalogueItem> getHoldList();
    int getCardNumber();
    void addHold(const CatalogueItem& hold);
    void removeLoan(const CatalogueItem& item);
    void removeHold(const CatalogueItem& item);
    Loan* getLoanForItem(const CatalogueItem& item);
};
