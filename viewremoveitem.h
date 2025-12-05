#ifndef VIEWREMOVEITEM_H
#define VIEWREMOVEITEM_H

#include <QWidget>
#include "catalogueitem.h"

namespace Ui {
class ViewRemoveItem;
}

class ViewRemoveItem : public QWidget
{
    Q_OBJECT

public:
    explicit ViewRemoveItem(QWidget *parent = nullptr, const CatalogueItem& item = CatalogueItem());
    ~ViewRemoveItem();
    QSize sizeHint() const{
        return QSize(300, 100);
    }
    CatalogueItem getItem(){return item;}


signals:
    void offRemoveItem();;
private slots:
    void on_removeItemButton_clicked();

private:
    CatalogueItem item;
    Ui::ViewRemoveItem *ui;
};

#endif // VIEWREMOVEITEM_H
