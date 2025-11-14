#ifndef BROWSECATALOGUE_H
#define BROWSECATALOGUE_H
#include "catalogue.h"
#include <QMainWindow>
#include "viewItem.h"
#include "viewstatus.h"

namespace Ui {
class BrowseCatalogue;
}

class BrowseCatalogue : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrowseCatalogue(QWidget *parent = nullptr, Catalogue catalogue = Catalogue(), Patron* patron = nullptr);
    ~BrowseCatalogue();
    vector<item*> itemSubList;
signals:
    void someHappened();

private slots:
    void getSomeItem();

    void on_accountButton_clicked();

private:
    Ui::BrowseCatalogue *ui;
    Catalogue catalogue;
    Patron* patron;
    int bookToAdd = -1;
};

#endif // BROWSECATALOGUE_H
