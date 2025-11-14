#include "viewauth.h"
#include "ui_viewauth.h"
#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include <QApplication>
#include "Book.cpp"
#include "Magazine.cpp"
#include "digitalMedia.cpp"
#include "loan.h"
#include "viewItem.h"

Catalogue System::catalogue1;
System ViewAuth::hinLibs;
Patron ViewAuth::mainPatron;

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
    int index = ViewAuth::hinLibs.systemAuth(username, pass);
    if (ViewAuth::hinLibs.systemAuth(username, pass) != -1){
        ViewAuth::loginSuccessful = true;
        this->hide();
        // Sends a signal about the success
        Patron newPatron = ViewAuth::hinLibs.getPatronAtIndex(index);
        mainPatron = newPatron;
        emit ViewAuth::getLoginSuccess();
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
    Patron patron2("Chris", "chris@hotmail.com", 1234);
    Patron patron3("Hunk", "hunk@gmail.com", 2068);
    Patron patron4("Albert", "albert@yahoo.com", 2005);
    Patron patron5("Ethan", "ethan@gmail.com", 1098);

    ViewAuth::hinLibs.addPatron(patron1);
    ViewAuth::hinLibs.addPatron(patron2);
    ViewAuth::hinLibs.addPatron(patron3);
    ViewAuth::hinLibs.addPatron(patron4);
    ViewAuth::hinLibs.addPatron(patron5);
    w.show();

    // 5 Fictional Books
    Book book1("9780385660075", "The Kite Runner", "Khaled Hosseini", 2003, "Good", "Fiction", 8);
    Book book2("9780385660076", "A Thousand Splendid Suns", "Khaled Hosseini", 2007, "Like New", "Fiction", 12);
    Book book3("9780143128540", "The Alchemist", "Paulo Coelho", 1988, "Good", "Fiction", 5);
    Book book4("9780062315007", "The Catcher in the Rye", "J.D. Salinger", 1951, "Fair", "Fiction", 3);
    Book book5("9780374533557", "The Glass Castle", "Jeannette Walls", 2005, "Good", "Memoir", 7);

    // 5 Non-Fictional Books
    NonFiction NFBook1("500.23", "9780062316097", "The Sixth Extinction: An Unnatural History", "Elizabeth Kolbert", 2014, "Excellent", "Science", 6);
    NonFiction NFBook2("973.004", "9780143128540", "The Alchemist", "Paulo Coelho", 1988, "Like New", "Self-Help", 5);
    NonFiction NFBook3("940.531", "9780062315007", "The Diary of a Young Girl", "Anne Frank", 1947, "Good", "Biography", 3);
    NonFiction NFBook4("973.22", "9780374533557", "The Glass Castle", "Jeannette Walls", 2005,  "Fair", "Memoir", 8);
    NonFiction NFBook5("000.000", "9780316336339", "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 2011, "Excellent", "History", 15);

    // 3 Magazines
    Magazine magazine1(24045, "2023-01-01", "Natural Geography", "HB Studios", 1996, "Great", "Magazine", 0);
    Magazine magazine2(33789, "2024-03-12", "Culinary Chronicles", "TastyPress Ltd.", 2008, "Very Good", "Magazine", 4);
    Magazine magazine3(98231, "2023-09-28", "Space Frontier Weekly", "Orbit Publications", 2019, "Good", "Magazine", 2);

    // 3 Movies
    digitalMedia movie1("Horror", "14+", "movie", "Black Phone 2", "Landline Co.", 2025, "Superb", "digitalMedia", 5);
    digitalMedia movie2("Anime/Action", "16+", "movie", "Demon Slayer: Infinity Arc", "Ufotable Studios", 2024, "Excellent", "digitalMedia", 7);
    digitalMedia movie3("Action/Thriller", "18+", "movie", "The Raid", "XYZ Films", 2011, "Good", "digitalMedia", 3);

    // 4 Video Games
    digitalMedia videoGame1("Adventure", "17+", "video-game", "A plague tale requiem", "Focus", 2020, "Good", "digitalMedia", 0);
    digitalMedia videoGame2("Stealth", "17+", "video-game", "The Last Of Us", "Naughty Dogs", 2013, "Ok", "digitalMedia", 1);
    digitalMedia videoGame3("Action", "17+", "video-game", "Elden Ring", "FromSoftware", 2020, "Excellent", "digitalMedia", 2);
    digitalMedia videoGame4("Choice", "18+", "video-game", "Dispatch", "Telltale Games", 2025, "Poor", "digitalMedia", 3);

    System::catalogue1.addItem(book1);
    System::catalogue1.addItem(book2);
    System::catalogue1.addItem(book3);
    System::catalogue1.addItem(book4);
    System::catalogue1.addItem(book5);

    System::catalogue1.addItem(NFBook1);
    System::catalogue1.addItem(NFBook2);
    System::catalogue1.addItem(NFBook3);
    System::catalogue1.addItem(NFBook4);
    System::catalogue1.addItem(NFBook5);

    System::catalogue1.addItem(movie1);
    System::catalogue1.addItem(movie2);
    System::catalogue1.addItem(movie3);

    System::catalogue1.addItem(magazine1);
    System::catalogue1.addItem(magazine2);
    System::catalogue1.addItem(magazine3);

    System::catalogue1.addItem(videoGame1);
    System::catalogue1.addItem(videoGame2);
    System::catalogue1.addItem(videoGame3);
    System::catalogue1.addItem(videoGame4);


    // Emits a signal when the user succesfully logs in, to now open the catalogue screen
    BrowseCatalogue c(nullptr, System::catalogue1);
    QObject::connect(&w, &ViewAuth::getLoginSuccess, &c, &BrowseCatalogue::show);
    //Loan(book1, tm());
    for (int i = 0; i < c.itemSubList.size(); i++){
            QObject::connect(c.itemSubList.at(i), &item::onLoanState, [&c, i, &w, book1]{
                w.mainPatron.addLoan(Loan(c.itemSubList.at(i)->getMyItem(), tm()));
                std::cout << w.mainPatron.getLoansSize();
                std::cout << c.itemSubList.at(i)->getMyItem().getTitle();
            });
    }

    return a.exec();
}

