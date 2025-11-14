#ifndef ACCOUNTSTATUS_H
#define ACCOUNTSTATUS_H

#include <string>
#include <vector>
#include <iterator>
#include "catalogueitem.h"
#include "patron.h"

using namespace std;

class AccountStatus
{
public:
    AccountStatus(Patron* p);

    int getBalance();
    vector<Loan> getLoans();
    const map<string, int> getHoldList();

private:
    bool borrowingPrivelages;
    int fineBalance;
    Patron person;
    vector<Loan> loans; //loans on the user's account
    vector<CatalogueItem> holds; // items on hold
};

#endif // ACCOUNTSTATUS_H
