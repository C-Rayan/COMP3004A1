#include "viewItem.h"
#include "ui_viewItem.h"
#include "patron.h"

item::item(QWidget *parent, const CatalogueItem& item): QWidget(parent), myItem(item), ui(new Ui::item){
    // Set all the labels to what they're supposed the item's value
    ui->setupUi(this);
    ui->txtTitle_2->setText(QString::fromStdString(myItem.getTitle()));
    ui->txtAuthor_2->setText(QString::fromStdString(myItem.getAuthor()));
    ui->txtFormat_2->setText(QString::fromStdString(myItem.getFormat()));
    ui->txtAvailable_2->setText(QString::fromStdString(myItem.getStatus()));
}

item::~item()
{
    delete ui;
}


void item::on_AddLoanButton_clicked(){
    // Sends a signal when you add a loan
    emit onLoanState();
}


void item::on_AddHoldButton_clicked(){
    // Sends a signal when you add a hold
    emit onHoldState();
}


void item::on_ReturnLoanButton_clicked(){
    // Checks that the returnloanbutton is enabled but the addholdbutton is disabled (Returns only when its added)
    if (this->findChild<QPushButton*>("ReturnLoanButton")->isEnabled())
        if (!(this->findChild<QPushButton*>("AddLoanButton")->isEnabled()))
            emit offLoanState();
}


void item::on_ReturnHoldButton_clicked(){
    // Checks that the returnholdbutton is enabled but the addholdbutton is disabled. (Returns only when its added)
    if (this->findChild<QPushButton*>("ReturnHoldButton")->isEnabled())
        if (!(this->findChild<QPushButton*>("AddHoldButton")->isEnabled()))
            emit offHoldState();
}

