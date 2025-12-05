#include "viewauth.h"
#include "qtextedit.h"
#include "ui_viewauth.h"
#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include <QApplication>
#include "Book.cpp"
#include "Magazine.cpp"
#include "digitalMedia.cpp"
#include "loan.h"
#include "viewItem.h"
#include  "editcatalogue.h"

Catalogue System::catalogue1;
System ViewAuth::hinLibs;
Patron ViewAuth::mainPatron;
Librarian* ViewAuth::mainLibrarian = nullptr;


ViewAuth::ViewAuth(QWidget *parent): QMainWindow(parent), ui(new Ui::ViewAuth)
{
    ui->setupUi(this);
    // Create a new database and set the name
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Path may cause issues
    db.setDatabaseName("C:/Users/chray/Downloads/COMP3004A1-D2_V3/COMP3004A1-D2_V3/inventory.db");
    if (!db.open()){
        qDebug() << "Error" << db.lastError();
    }
    else{
        qDebug() << "Working";
    }
}

ViewAuth::~ViewAuth()
{
    delete ui;
}

// Simple in memory check to determine if username and pin are correct
void ViewAuth::on_buttonSignIn_clicked()
{
    std::string user;
    int pass;
    user = ui->txtUser->text().toStdString();
    pass = ui->txtPass->text().toInt();
    std::string declare = ViewAuth::hinLibs.systemAuth(user, pass);

    if (declare == "Patron"){
        ViewAuth::loginSuccessful = true;
        this->hide();
        /* Uses an SQL Query to retrieve the person with the name from the DB */
        QSqlQuery query;
        query.prepare("SELECT * FROM PATRONS WHERE card_number = ?");
        query.addBindValue(std::stoi(user));
        query.exec();
        while (query.next()){
            int id = query.value(0).toInt();
            std::string name = query.value(1).toString().toStdString();
            std::string email = query.value(2).toString().toStdString();
            int pin = query.value(3).toInt();
            int numLoans = query.value(4).toInt();
            mainPatron = Patron(id, name, email, pin, numLoans);
        }
        emit ViewAuth::getLoginSuccess();
    }
    else if (declare == "Librarian"){
        this->hide();
        QSqlQuery query;
        query.prepare("SELECT * FROM Librarians WHERE name = ?");
        query.addBindValue(QString::fromStdString(user));
        query.exec();
        while (query.next()){
            std::string name = query.value("name").toString().toStdString();
            std::string email = query.value("email").toString().toStdString();
            int pin = query.value("pin").toInt();
            mainLibrarian = new Librarian(name, email, System::catalogue1, 0, pin);
        }
        emit  ViewAuth::LibrarianLogin();
    }
    else{
        ui->txtUser->clear();
        ui->txtPass->clear();
        ui->loginMsg->setText("Maybe you put the username or password wrong?");
    }
}

// Get the intiial loans for this patron from the database and load them in memory
void ViewAuth::loadLoans(){
    QSqlQuery query("SELECT item_id FROM loans WHERE patron_id = ?");
    query.addBindValue(mainPatron.getId());
    query.exec();
    int count = 0;
    while (query.next()){
        int iid = query.value("item_id").toInt();
        // Creates new time, need to fix to get old time
        Loan loan = Loan(System::catalogue1.findItem(iid), tm());
        ViewAuth::mainPatron.addLoan(loan);
        count++;
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewAuth w;
    w.show();

    // patron1 has cardNumber "1", patron2 has cardnumber "2", patron3 has cardnumber "3" and so on
    // To test 1:
    // Write cardnumber: "1" and pass: "0000"
    // same for the rest

    // Query the DB to find all items in our list and store them in our list (Can be done without list, but requires too many lookups)
    // We do need to load all our items to make them visible
    QSqlQuery findItems("SELECT * FROM CATALOGUE");
    findItems.exec();
    while (findItems.next()){
        int cid = findItems.value(0).toInt();
        std::string title = findItems.value("title").toString().toStdString();
        std::string author = findItems.value("author").toString().toStdString();
        int publishYear = findItems.value("publish_year").toInt();
        std::string condition = findItems.value("condition").toString().toStdString();
        std::string format = findItems.value("format").toString().toStdString();
        int quantity = findItems.value("quantity").toInt();
        CatalogueItem *item = new CatalogueItem(cid, title, author, publishYear, condition, format, quantity);
        System::catalogue1.addItem(*item);
    }


    Librarian librarian("Bob", "bob@gmail.com", System::catalogue1, 100, 6769);
    ViewAuth::hinLibs.addLibrarian(librarian);


    // Emits a signal when the user succesfully logs in, to now open the catalogue screen
    BrowseCatalogue c(nullptr, System::catalogue1, &ViewAuth::mainPatron);
    //QObject::connect(&w, &ViewAuth::getLoginSuccess, &c, &BrowseCatalogue::show);

    // Changed this because we need to load the loans for this patron into memory now
    // Use SQL query to bring our laons/holds into C++ objects
    QObject::connect(&w, &ViewAuth::getLoginSuccess, [&w, &c] {
        w.loadLoans();
        c.show();

        for (int i = 0; i < ViewAuth::mainPatron.getLoans().size(); i++){
            int id = ViewAuth::mainPatron.getLoans().at(i).getItem().getCID();
               for (int j = 0; j < c.itemSubList.size(); j++){
                 if (c.itemSubList.at(j)->getItemID() == id){
                       for (int k = 0; k < c.itemSubList.at(j)->findChildren<QPushButton*>().size(); k++){
                           c.itemSubList.at(j)->findChildren<QPushButton*>().at(k)->setEnabled(false);
                       }
                       c.itemSubList.at(j)->findChild<QPushButton*>("ReturnLoanButton")->setEnabled(true);
                       break;
                 }
             }
        }

    });


    bool value = false;
    //Loan(book1, tm());






    // This represents our viewable GUI model, which will stay in-memory, since it stores viewable/gui data (Labels and buttons)
    for (int i = 0; i < c.itemSubList.size(); i++){
        // Checks for an add signal
        QObject::connect(c.itemSubList.at(i), &item::onLoanState, [&c, i, &w, &value]{
            std::time_t now = std::time(nullptr);
            // Convert to local tm structure
            std::tm* local_time = std::localtime(&now);
            // Adds the loan to this patron and disables appropriate buttons
          //
          // CHANGE
          //
            value = w.mainPatron.addLoan2(Loan(c.itemSubList.at(i)->getMyItem(), *local_time));
            // If value was succesfully added, then disable button
            if (value){
                // Disable every button except the one that lets you return the loan
                for (int j = 0; j < c.itemSubList.at(i)->findChildren<QPushButton*>().size(); j++){
                    c.itemSubList.at(i)->findChildren<QPushButton*>().at(j)->setEnabled(false);
                }
                c.itemSubList.at(i)->findChild<QPushButton*>("ReturnLoanButton")->setEnabled(true);

                // Check if item is still available
                QSqlQuery query;
                query.prepare("SELECT status FROM catalogue WHERE cid=?");
                query.addBindValue(c.itemSubList.at(i)->getMyItem().getCID());
                query.exec();
                if (query.next()){
                    if (query.value("status").toBool() == false){
                        c.itemSubList.at(i)->findChildren<QTextEdit*>().at(3)->setText("Unavailable");
                    }
                }
            }
        });

        // Checks for a hold signal
        QObject::connect(c.itemSubList.at(i), &item::onHoldState, [&c, i, &w]{
            // Adds the hold to this patron and disables appropriate buttons
            w.mainPatron.addHold(c.itemSubList.at(i)->getMyItem());

            for (int j = 0; j < c.itemSubList.at(i)->findChildren<QPushButton*>().size(); j++){
                c.itemSubList.at(i)->findChildren<QPushButton*>().at(j)->setEnabled(false);
            }
            c.itemSubList.at(i)->findChild<QPushButton*>("ReturnHoldButton")->setEnabled(true);
        });

        // Checks for a remove signal
        QObject::connect(c.itemSubList.at(i), &item::offLoanState, [&c, i, &w]{
           // Check if item was added is done in viewItem.cpp
            // Removes the loan to this patron and enables all buttons
            w.mainPatron.removeLoan(c.itemSubList.at(i)->getMyItem());

            for (int j = 0; j < c.itemSubList.at(i)->findChildren<QPushButton*>().size(); j++){
                c.itemSubList.at(i)->findChildren<QPushButton*>().at(j)->setEnabled(true);
            }

            QSqlQuery query;
            query.prepare("SELECT status FROM catalogue WHERE cid=?");
            query.addBindValue(c.itemSubList.at(i)->getMyItem().getCID());
            query.exec();
            if (query.next()){
                if (query.value("status").toBool() == true){
                    c.itemSubList.at(i)->findChildren<QTextEdit*>().at(3)->setText("Available");
                }
            }


        });

        // Checks for a removeHold signal
        QObject::connect(c.itemSubList.at(i), &item::offHoldState, [&c, i, &w]{
            // Check if item was added is done in viewItem.cpp
            // Removes the hold to this patron and enables all buttons
            w.mainPatron.removeHold(c.itemSubList.at(i)->getMyItem());

            for (int j = 0; j < c.itemSubList.at(i)->findChildren<QPushButton*>().size(); j++){
                c.itemSubList.at(i)->findChildren<QPushButton*>().at(j)->setEnabled(true);
            }
        });

    }
    //Libarian successfully loggged in
    QObject::connect(&w, &ViewAuth::LibrarianLogin, [&w]{
        // Allocate on heap
        EditCatalogue* editC = new EditCatalogue(nullptr, ViewAuth::mainLibrarian);
        editC->show();

        // Connect signals for items
        for(int i = 0; i < editC->itemList.size(); i++){
            QObject::connect(editC->itemList.at(i), &ViewRemoveItem::offRemoveItem,
                [editC, i, &w]{
                    w.mainLibrarian->removeItem(editC->itemList.at(i)->getItem());
                });
        }

        // Optional: delete editC when closed
        QObject::connect(editC, &QWidget::destroyed, editC, &QObject::deleteLater);
    });

    return a.exec();
}

