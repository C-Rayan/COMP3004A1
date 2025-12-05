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
    explicit item(QWidget *parent = nullptr,  int id = 1);
    ~item();
    QSize sizeHint() const{
        return QSize(300, 100);
    }
    CatalogueItem getMyItem(){
        return myItem;
    }
    int getItemID();
signals:
    void onLoanState();
    void onHoldState();
    void offHoldState();
    void offLoanState();

private slots:
    void on_AddLoanButton_clicked();
    void on_AddHoldButton_clicked();
    void on_ReturnLoanButton_clicked();
    void on_ReturnHoldButton_clicked();

private:
   // vector<Patron> loanedPatrons;
    CatalogueItem myItem;
    // We have to store somethign to query the item
    int itemId;
    Ui::item *ui;

};

#endif // VIEWITEM_H
