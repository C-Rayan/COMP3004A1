#ifndef EDITPATRON_H
#define EDITPATRON_H

#include "patron.h"
#include <QDialog>

namespace Ui {
class EditPatron;
}

class EditPatron : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatron(QWidget *parent = nullptr, Patron patron = Patron());
    ~EditPatron();
    void loadData(Patron& patron);

private:
    Ui::EditPatron *ui;
};

#endif // EDITPATRON_H
