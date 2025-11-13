#include "viewItem.h"
#include "ui_viewItem.h"
#include "patron.h"


item::item(QWidget *parent, const CatalogueItem& item): QWidget(parent), myItem(item), ui(new Ui::item){
    ui->setupUi(this);
    ui->txtTitle_2->setText(QString::fromStdString(myItem.getTitle()));
    setStyleSheet("background-color: lightblue; border: 1px solid red;");
}
//
// ui->txtAvailable_2->setText((QString&)myItem.getStatus());
// ui->txtFormat_2->setText((QString&) myItem.getFormat());

item::~item()
{
    delete ui;
}



void item::on_pushButton_3_clicked()
{
    emit onLoanState();
}

void item::getAnItem(){
    emit
}
