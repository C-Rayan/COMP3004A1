#include "viewstatus.h"
#include "ui_viewStatus.h"

viewStatus::viewStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewStatus),
    status(NULL)
{
    ui->setupUi(this);
    //loadData();
}

viewStatus::viewStatus(QWidget *parent, Patron* person) :
    QWidget(parent),
    ui(new Ui::viewStatus),
    status(*new AccountStatus(person))
{
    ui->setupUi(this);
    loadData();
}


viewStatus::~viewStatus()
{
    delete ui;
}

//connect
void viewStatus::on_backButton_clicked()
{
    close();

}

void viewStatus::loadData(){
    char time[50];
    tm temp;
    for (Loan loan: status.getLoans() ) {
        temp = loan.getDueDate();
        strftime(time,50, "%m/%d/%y", &temp);
        //Converts values to Qstrings  then adds  them to the correcct lists
        ui->loansTitleList->addItem(QString::fromStdString(loan.getItem().getTitle()));
        ui->dueDateList->addItem(QString::fromStdString(time));
        ui->daysRemList->addItem(QString::fromStdString(to_string(loan.getRemainingDays())) );
    }

    map<string, int> holds = status.getHoldList();
    for (auto hold :holds ) {
        ui->holdsTitleList->addItem(QString::fromStdString(hold.first));
        ui->holdsPositionList->addItem(QString::fromStdString(to_string(hold.second)));
    }*/

}
