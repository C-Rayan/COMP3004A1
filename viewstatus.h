#ifndef VIEWSTATUS_H
#define VIEWSTATUS_H

#include <QWidget>
#include "accountStatus.h"

namespace Ui {
class viewStatus;
}

class viewStatus : public QWidget
{
    Q_OBJECT

public:
    explicit viewStatus(QWidget *parent = nullptr);
    viewStatus(QWidget *parent = nullptr, Patron *patron = nullptr);
    ~viewStatus();
signals:
    void openStatus();

private slots:
    void on_backButton_clicked();

private:
    Ui::viewStatus *ui;
    AccountStatus status;
    void loadData();
};

#endif // VIEWSTATUS_H
