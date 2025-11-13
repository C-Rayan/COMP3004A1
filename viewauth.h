#ifndef VIEWAUTH_H
#define VIEWAUTH_H

#include <QMainWindow>
#include "system.h"

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

    static System hinLibs;

signals:
    void getLoginSuccess();

private slots:
    std::optional<Patron> on_buttonSignIn_clicked();

private:
    Ui::ViewAuth *ui;
    bool loginSuccessful = false;
    //static Patron* mainPatron;
};
#endif // VIEWAUTH_H
