#include "CatalogueItem.h"

class digitalMedia: public CatalogueItem{
private:
    string genre;
    string rating;
    string type;
public:
    digitalMedia(int cid, const string& genre, const string& rating, const string& type, const string& title, const string& author, int publishYear, const string& condtion, const string& format, int quantity):
        genre(genre), rating(rating), type(type), CatalogueItem(cid, title, author, publishYear, condtion, format,quantity){};

    //getters
    const string& getGenre();
    const string& getRating();
    const string& getType();

};
