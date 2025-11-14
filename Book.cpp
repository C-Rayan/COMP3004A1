#include "CatalogueItem.h"

class Book: public CatalogueItem{
private:
    string isbn;

public:
    Book(const string& isbn, const string& title, const string& author, int publishYear, const string& condtion, const string& format, int quantity): isbn(isbn), CatalogueItem(title, author, publishYear, condtion, format,quantity){} ;
    const string& getISBN(){return isbn;};
};

class NonFiction: public Book{
private:
    string dewyNumber;
public:
    NonFiction(const string& deweyNumber, const string& isbn, const string& title, const string& author, int publishYear, const string& condtion, const string& format, int quantity): dewyNumber(deweyNumber), Book(isbn, title, author, publishYear, condtion, format,quantity){};
    const string& getDewyNumber(){return dewyNumber;};
};
