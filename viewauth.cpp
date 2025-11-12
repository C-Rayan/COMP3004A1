#include "viewauth.h"
#include "ui_viewauth.h"
#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include <QApplication>

Catalogue System::catalogue1;
System ViewAuth::hinLibs;

ViewAuth::ViewAuth(QWidget *parent): QMainWindow(parent), ui(new Ui::ViewAuth)
{
    ui->setupUi(this);

}

ViewAuth::~ViewAuth()
{
    delete ui;
}

void ViewAuth::on_buttonSignIn_clicked()
{
    std::string username;
    int pass;
    username = ui->txtUser->text().toStdString();
    pass = ui->txtPass->text().toInt();
    if (ViewAuth::hinLibs.systemAuth(username, pass)){
        ui->loginMsg->setText("Success: You will be redirected now");
    }
    else{
        ui->txtUser->clear();
        ui->txtPass->clear();
        ui->loginMsg->setText("Maybe you put the username or password wrong?");
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewAuth w;

    Patron patron1("Leon", "leon@gmail.com", 0000);
    Patron patron2("Chris", "chris@gmail.com", 1234);
    Patron patron3("Hunk", "hunk@gmail.com", 2068);
    Patron patron4("Albert", "albert@gmail.com", 2005);
    Patron patron5("Ethan", "ethan@gmail.com", 1098);




    //System::catalogue1.addItem();
    ViewAuth::hinLibs.addPatron(patron1);
    ViewAuth::hinLibs.addPatron(patron2);
    ViewAuth::hinLibs.addPatron(patron3);
    ViewAuth::hinLibs.addPatron(patron4);
    ViewAuth::hinLibs.addPatron(patron5);

    w.show();

    BrowseCatalogue c;



    // Show the window to user
    return a.exec();
}

