#ifndef VIEWACCOUNTSTATUS_H
#define VIEWACCOUNTSTATUS_H

#include <QWidget>

namespace Ui {
class viewAccountStatus;
}

class viewAccountStatus : public QWidget
{
    Q_OBJECT

public:
    explicit viewAccountStatus(QWidget *parent = nullptr);
    ~viewAccountStatus();

private:
    Ui::viewAccountStatus *ui;
};

#endif // VIEWACCOUNTSTATUS_H
