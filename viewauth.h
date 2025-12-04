#ifndef VIEWAUTH_H
#define VIEWAUTH_H

#include <QMainWindow>
#include "system.h"
#include "librarian.h"

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
    static Patron mainPatron;
    static Librarian* mainLibrarian;

    static System hinLibs;

signals:
    void getLoginSuccess();
    void Success();
    void LibrarianLogin();

private slots:
    void on_buttonSignIn_clicked();

private:
    Ui::ViewAuth *ui;
    bool loginSuccessful = false;
};
#endif // VIEWAUTH_H
