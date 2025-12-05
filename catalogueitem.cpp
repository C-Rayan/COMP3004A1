#include "catalogueitem.h"
#include "qsqlquery.h"

CatalogueItem::CatalogueItem(int cid, const string& title, const string& author, int publishYear, const string& condition, const string& format, int quantity){
    this->cid = cid;
    this->title = title;
    this->author = author;
    this->publishYear = publishYear;
    this->status = "Unavailable";
    this->condition = condition;
    this->format = format;
    this->quantity = quantity;
    if (quantity > 0){
        this->status = "Available";
    }

}

void CatalogueItem::reduceQuantity(int amount){
    if (this->quantity - amount >= 0){
        this->quantity = (this->quantity) - amount;
        QSqlQuery query;
        // Update the quantity to persist in the DB
        std::cout << "Quantity: ";
        std::cout << quantity << std::endl;
        query.prepare("UPDATE catalogue SET quantity = ? WHERE cid = ?");
        query.addBindValue(this->quantity);
        query.addBindValue(this->cid);
        query.exec();
    }
    else{
        std::cout << "The quantity cannot reduce below 0" << std::endl;
    }
}


void CatalogueItem::increaseQuantity(int amount){
    this->quantity = this->quantity + amount;
    std::cout << "Amount: ";
    std::cout << amount << std::endl;
    QSqlQuery query;
    query.prepare("UPDATE catalogue SET quantity = ? WHERE cid = ?");
    query.addBindValue(this->quantity);
    query.addBindValue(this->cid);
    query.exec();
}

int CatalogueItem::searchQueue(string name){
    //Looks for the iteraator pointing the specified name
    auto it = find(holds.begin(),holds.end(), name);
    int index =-1;
    if(it != holds.end()){
        index = distance(holds.begin(), it);
    }
    return index;
}


// Checks if two items are equivalent
bool CatalogueItem::equals(const CatalogueItem& item){
    if (this->author == item.author && this->condition == item.condition &&
        this->format == item.format && this->publishYear == item.publishYear &&
        this->title == item.title && this->status == item.status)
        return true;
    return false;
}

int CatalogueItem::getCID() const{
    return this->cid;
}

void CatalogueItem::setStatus(std::string status){
    this->status = status;
    QSqlQuery query;
    query.prepare("UPDATE catalogue SET status = ? WHERE cid = ?");
    query.addBindValue(QString::fromStdString(this->status));
    query.addBindValue(this->cid);
    query.exec();
}
