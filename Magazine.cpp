#include "catalogueItem.h"

class Magazine: public CatalogueItem{
private:
    int issueNo;
    const string& publishDate;
public:
    Magazine(int cid, int issueNo, const string& publishDate, const string& title, const string& author, int publishYear, const string& condtion, const string& format, int quantity):issueNo(issueNo), publishDate(publishDate) , CatalogueItem(cid, title, author, publishYear, condtion, format,quantity){};

    int getIssueNo(){return issueNo;};
    const string& getPublishDate(){ return publishDate;};

};
