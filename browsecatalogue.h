#ifndef BROWSECATALOGUE_H
#define BROWSECATALOGUE_H
#include "catalogue.h"
#include <QMainWindow>

namespace Ui {
class BrowseCatalogue;
}

class BrowseCatalogue : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrowseCatalogue(QWidget *parent = nullptr, Catalogue catalogue = Catalogue());
    ~BrowseCatalogue();


private:
    Ui::BrowseCatalogue *ui;
    Catalogue catalogue;

};

#endif // BROWSECATALOGUE_H
