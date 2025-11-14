#ifndef BROWSECATALOGUE_H
#define BROWSECATALOGUE_H
#include "catalogue.h"
#include <QMainWindow>
#include "viewItem.h"

namespace Ui {
class BrowseCatalogue;
}

class BrowseCatalogue : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrowseCatalogue(QWidget *parent = nullptr, Catalogue catalogue = Catalogue());
    ~BrowseCatalogue();
    vector<item*> itemSubList;
signals:
    void someHappened();

private slots:
    void getSomeItem();

private:
    Ui::BrowseCatalogue *ui;
    Catalogue catalogue;
    int bookToAdd = -1;
};

#endif // BROWSECATALOGUE_H
