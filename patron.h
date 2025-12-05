#ifndef PATRON_H
#define PATRON_H
#include <vector>
#include <string>
#include "loan.h"
#include <string>
#include <QSqlQuery>

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
    // NEED TO FIX LATER BY GETTING FROM DB INSTEAD OF THIS WAY
    int numLoans;

public:
    Patron(int cardNumber, const string& name, const string& email, int pin, int numLoans);

    // Used to create an empty patron (Whose values will be stored later)
    Patron();
    int getPin();
    std::string getName();
    void ViewAccountStatus();
    int getLoansSize();
    bool getLoanSuccess();
    std::vector<Loan> getLoans();
    std::vector<CatalogueItem> getHoldList();
    int getCardNumber();
    void addHold(CatalogueItem hold);
    void removeLoan(const CatalogueItem& item);
    void removeHold(const CatalogueItem item);
    Loan* getLoanForItem(const CatalogueItem& item);

    void addLoan(const Loan& loan);
    bool addLoan2(const Loan& loan);
    int getId() {return cardNumber;}
    void loadLoans();
    void loadHolds();

};
#endif
