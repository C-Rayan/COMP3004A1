#ifndef ITEM_H
#define ITEM_H
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

private:
    CatalogueItem myItem;
    Ui::item *ui;

};

#endif // ITEM_H
