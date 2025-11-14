#include "accountStatus.h"
#include <map>

AccountStatus::AccountStatus(Patron* p): person(*p){
    loans = p->getLoans();
    holds = p->getHoldList();
    borrowingPrivelages = true;
    fineBalance =0; // change to an arguement when implenting fines

}

vector<Loan> AccountStatus::getLoans(){
    return loans;
}

const string AccountStatus::getPatronName() {
    return person.getName();
}

const map<string, int> AccountStatus::getHoldList(){
    //Key: title of item on hold, Value: patron's postion in queue
    map<string, int> pairs;
    for(CatalogueItem item: holds){
        int  index = item.searchQueue(person.getName());
        if(index == -1){
            continue;
        }
        else{
           // pairs.insert({item, index});
        }
    }
    return pairs;
}
