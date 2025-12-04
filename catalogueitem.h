#ifndef CATALOGUEITEM_H
#define CATALOGUEITEM_H

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <ctime>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class CatalogueItem{
private:
    string title;
    string author;
    int publishYear;
    string status;
    string condition;
    string format;
    string dueDate; // consider turning into date type
    int quantity;
    list<string> holds;

public:
    // compares both addresses tocheck if they are same
    bool operator==(const CatalogueItem& check) const{
        return this == &check;
    }
    //Constructor
    CatalogueItem(const string& title, const string& author, int publishYear, const string& condtion, const string& format, int quantity);
    // Base constructor, not useful, only used to force the default because parameter of QWidget functions
    CatalogueItem():
        title("placeholder"), author("author"), publishYear(0), status("unavailable"), condition("unknown"), format("unknown"), quantity(-1)
    {}
    //getters
    const string& getTitle(){return title;};
    const string& getAuthor(){return author;};
    const string& getStatus(){return status;};
    const string& getFormat(){return format;};
    const string& getCondition(){return condition;};
    int getQuantity(){return quantity;};
    const string& getDueDate(){return dueDate;};
    const list<string> getListOfHolders(){return holds;};

    void reduceQuantity(int amount);
    void increaseQuantity(int amount);
    void setStatus(std::string status){this->status = status;}
    int  searchQueue(string name);
    bool equals(const CatalogueItem& item);
    void addToQueue(string name);
    void removeFromQueue(string name);


};

#endif
