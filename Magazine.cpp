#include "CatalogueItem.h"

class Magazine: public CatalogueItem{
private:
    int issueNo;
    const string& publishDate;
public:
    Magazine(int issueNo, const string& publishDate, const string& title, const string& author, int publishYear, const string& status, const string& condtion, const string& format, int quantity):issueNo(issueNo), publishDate(publishDate) , CatalogueItem(title, author, publishYear, status, condtion, format,quantity){};

    int getIssueNo(){return issueNo;};
    const string& getPublishDate(){ return publishDate;};

};
