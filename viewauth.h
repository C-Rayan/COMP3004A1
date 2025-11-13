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

    static System hinLibs;

signals:
    void getLoginSuccess();

private slots:
    void on_buttonSignIn_clicked();

private:
    Ui::ViewAuth *ui;
    bool loginSuccessful = false;
};
#endif // VIEWAUTH_H
