#include <string>
#include "patron.h"

int Patron::curUsers = 0;
Patron::Patron(int cardNumber, const string& name, const string& email, int pin, int numLoans){
    this->cardNumber = cardNumber;
    this->name = name;
    this->email = email;
    this->pin = pin;
    this->numLoans = numLoans;
}

// Used to force QT's default parameters in some functions, is not used however
Patron::Patron(){
    name = "empty";
    email = "empty";
    pin = 438984913;
}

int Patron::getPin(){
    return pin;
}

std::string Patron::getName(){
    return name;
}


// Only used when loading in objects from db
void Patron::addLoan(const Loan& loan){
    this->myLoans.push_back(loan);
}


// D2 IMPLEMENTATION
bool Patron::addLoan2(const Loan& loan){
    std::cout << "ASDSA" << cardNumber << std::endl;

    // Checks if patron
    if (numLoans >= 3 || loan.getItem().getStatus() == "Unavailable"){
        return false;
    }
    // Affects in memory and DB
    loan.getItem().reduceQuantity(1);
    //loan.getItem().setStatus("Unavailable");
    this->myLoans.push_back(loan);
    numLoans++;
    // loan.getItem() returns local copy which it does work on
    // Not good for multiple, but in our case, only one host so it's fine
    // Persists works differently so that portion is fine
    if (loan.getItem().getQuantity()-1 <= 0){
        loan.getItem().setStatus("Unavailable");
        QSqlQuery updateStatus;
        updateStatus.prepare("UPDATE catalogue SET status = ? WHERE cid = ?");
        updateStatus.addBindValue(false);
        updateStatus.addBindValue(loan.getItem().getCID());
        updateStatus.exec();
    }

    QSqlQuery query1;
    query1.prepare("UPDATE PATRONS set numLoans = ? WHERE card_number = ?");
    query1.addBindValue(numLoans);
    query1.addBindValue(this->cardNumber);
    query1.exec();

    QSqlQuery query2;
    query2.prepare("INSERT into LOANS (due_date, PATRON_ID, ITEM_ID) values (?, ?, ?)");
    query2.addBindValue("2020-01-01");
    query2.addBindValue(this->cardNumber);

    query2.addBindValue(loan.getItem().getCID());
    query2.exec();
    return true;
    for (int i = 0; i < numLoans; i++){
        std::cout << "Quantity";
        std::cout << myLoans.at(i).getQuantity() << std::endl;
    }
}

int Patron::getLoansSize(){
    return this->myLoans.size();
}


std::vector<Loan> Patron::getLoans(){
    return myLoans;
}

std::vector<CatalogueItem> Patron::getHoldList(){
    return myHolds;
}

int Patron::getCardNumber(){
    return cardNumber;
}

void Patron::addHold(CatalogueItem hold){
    hold.addToQueue(name);
    this->myHolds.push_back(hold);
    /* Explanation of position variables in holds
     * Each hold has a position variable and a patron_id/item_id
     * As a patron has holds added, we query the database and find the latest position
     * For a certain item */
    QSqlQuery query;
    query.prepare("SELECT position FROM holds WHERE item_id = ?");
    query.addBindValue(hold.getCID());
    int position = 0;
    query.exec();
    while (query.next()){
        if (query.value(0).toInt() > position)
            position = query.value(0).toInt();
    }
    // Increment by 1 since it should be 1 more than the last position
    position += 1;
    QSqlQuery query2;

    query2.prepare("INSERT INTO holds (position, PATRON_ID, ITEM_ID) VALUES (?, ?, ?)");
    query2.addBindValue(position);
    query2.addBindValue(this->cardNumber);
    query2.addBindValue(hold.getCID());
    query2.exec();
}

// Method with implemented equals in CatalogueItem that checks all attributes
Loan* Patron::getLoanForItem(const CatalogueItem& item){
    for (int i = 0; i < myLoans.size(); i++){
        if (myLoans.at(i).getItem().equals(item)){
          return &myLoans.at(i);
       }
    }

    return nullptr;
}

// Removes a loan from a patron loans list D2 IMPLEMENTATION
void Patron::removeLoan(const CatalogueItem& item){
    if (myLoans.size() < 0){
        return;
    }
    Loan* selectLoan = getLoanForItem(item);
    const Loan& selectedLoan = *selectLoan;
    numLoans--;
    // Goes thru the whole vector to find all* (only 1) specific loan and delete it
    for (int i = 0; i < myLoans.size(); i++){
        if (myLoans.at(i).getItem().getCID() == selectedLoan.getItem().getCID()){
            myLoans.erase(myLoans.begin() + i);
        }
    }

    // Persists new amount of loans in DB aswell
    QSqlQuery query1;
    query1.prepare("UPDATE PATRONS set numLoans = ? WHERE card_number = ?");
    query1.addBindValue(numLoans);
    query1.addBindValue(this->cardNumber);
    query1.exec();

    // Deletes that loan from the DB aswell
    QSqlQuery query2;
    query2.prepare("DELETE FROM loans WHERE patron_id = ? AND item_id = ?");
    query2.addBindValue(this->getId());
    query2.addBindValue(selectedLoan.getItem().getCID());
    query2.exec();

    // Persists these values from their respective functions
    // For some reason, it's increasing quantity by 1 when set to 0. Unsure where other call is. Keep 0;
    selectedLoan.getItem().increaseQuantity(0);
    selectedLoan.getItem().setStatus("Available");
}

// Removes a hold from a patron hold list
void Patron::removeHold(const CatalogueItem item){
    cout<<myHolds.size() <<endl;
    if (myHolds.size() < 0){
        return;
    }
    // update the actual stored item
        for (CatalogueItem& hold : myHolds) {
            if (hold.equals(item)) {
                hold.removeFromQueue(name);
            }
        }
    // Goes thru the whole vector to find all* (only 1) specific hold and delete it
    myHolds.erase(std::remove(myHolds.begin(), myHolds.end(), item), myHolds.end());


    QSqlQuery query0;
    query0.prepare("SELECT position FROM holds where patron_id = ? and item_id = ?");
    query0.addBindValue(this->cardNumber);
    query0.addBindValue(item.getCID());
    query0.exec();
    int position = 0;
    if (query0.next()){
        position = query0.value("position").toInt();
    }

    QSqlQuery query1;
    query1.prepare("DELETE FROM holds where patron_id = ? and item_id = ?");
    query1.addBindValue(this->cardNumber);
    query1.addBindValue(item.getCID());
    query1.exec();

    QSqlQuery query2;
    std::cout << "Posi" << position << std::endl;
    // Update all positions that are bigger than the one we removed to be 1 less
    query2.prepare("UPDATE holds SET position = (position-1) WHERE position > ?");
    query2.addBindValue(position);
    query2.exec();


}





