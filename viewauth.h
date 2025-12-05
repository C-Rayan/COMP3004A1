#ifndef VIEWAUTH_H
#define VIEWAUTH_H

#include <QMainWindow>
#include "system.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


QT_BEGIN_NAMESPACE
namespace Ui {
class ViewAuth;
}
QT_END_NAMESPACE

class ViewAuth : public QMainWindow
{
    Q_OBJECT

public:
    ViewAuth(QWidget *parent = nullptr);
    ~ViewAuth();
    // static Patron& getMainPatron(){
    //     return *mainPatron;
    // }
    void loadLoans();

    static Patron mainPatron;

    static System hinLibs;

    static int mainCard;

signals:
    void getLoginSuccess();
    void Success();

private slots:
    void on_buttonSignIn_clicked();

private:
    Ui::ViewAuth *ui;
    bool loginSuccessful = false;
    QSqlDatabase db;
    //static Patron* mainPatron;
    void loadHolds();
};
#endif // VIEWAUTH_H
