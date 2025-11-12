#ifndef BROWSECATALOGUE_H
#define BROWSECATALOGUE_H
#include "catalogueitem.h"
#include <QMainWindow>

namespace Ui {
class BrowseCatalogue;
}

class BrowseCatalogue : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrowseCatalogue(QWidget *parent = nullptr);
    ~BrowseCatalogue();

private:
    Ui::BrowseCatalogue *ui;
};

#endif // BROWSECATALOGUE_H
