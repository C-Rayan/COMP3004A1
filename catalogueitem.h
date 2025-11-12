#ifndef CATALOGUEITEM_H
#define CATALOGUEITEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class CatalogueItem{
private:
    string title;
    string author;
    int publishYear;
    string status;
    string condtion;
    string format;
    int quantity;
    vector<string> holds;

public:
    //Constructor
    CatalogueItem(const string& title, const string& author, int publishYear, const string& status, const string& condition, const string& format, int quantity);

    //getters
    const string& getTitle();
    const string& getAuthor();
    const string& getStatus();
    const string& getFormat();
    const string& getCondtion();

    int getQuantity();

    bool equals(const CatalogueItem& item);

    void reduceQuantity(int amount);
    void increaseQuantity(int amount);



};

#endif
