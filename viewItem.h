#ifndef VIEWITEM_H
#define VIEWITEM_H
#include "catalogueitem.h"

#include <QWidget>

namespace Ui {
class item;
}


class item : public QWidget{
    Q_OBJECT
public:
    //explicit item(QWidget *parent = nullptr);
    explicit item(QWidget *parent = nullptr, const CatalogueItem& item = CatalogueItem());
    ~item();
    QSize sizeHint() const{
        return QSize(300, 100);
    }
    CatalogueItem getMyItem(){
        return myItem;
    }
signals:
    void onLoanState();
    //void addedAnItem();

private slots:
    //void getAnItem();
    void addedAnItemSlot();

    void on_AddLoanButton_clicked();

private:
   // vector<Patron> loanedPatrons;
    CatalogueItem myItem;
    Ui::item *ui;

};

#endif // VIEWITEM_H
