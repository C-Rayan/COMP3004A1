#ifndef EDITCATALOGUE_H
#define EDITCATALOGUE_H

#include <QWidget>
#include "librarian.h"
#include "viewItem.h"
#include "viewremoveitem.h"
Q_DECLARE_METATYPE(Patron)


namespace Ui {
class EditCatalogue;
}

class EditCatalogue : public QWidget
{
    Q_OBJECT
public:
    explicit EditCatalogue(QWidget *parent = nullptr);
    EditCatalogue(QWidget *parent = nullptr, Librarian* l = nullptr);
    ~EditCatalogue();
    void loadData();

   vector<ViewRemoveItem*> itemList;

private slots:
    void on_searchButton_clicked();

private:
    Librarian lib;
    Ui::EditCatalogue *ui;

};

#endif // EDITCATALOGUE_H
