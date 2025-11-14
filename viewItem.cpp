#include "viewItem.h"
#include "ui_viewItem.h"
#include "patron.h"

item::item(QWidget *parent, const CatalogueItem& item): QWidget(parent), myItem(item), ui(new Ui::item){
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




void item::addedAnItemSlot(){
     ui->AddLoanButton->setEnabled(false);
}


void item::on_AddLoanButton_clicked()
{
    emit onLoanState();
}

