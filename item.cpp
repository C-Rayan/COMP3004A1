#include "item.h"
#include "ui_item.h"



item::item(QWidget *parent, const CatalogueItem& item): QWidget(parent), myItem(item), ui(new Ui::item){
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    setStyleSheet("background-color: lightblue; border: 1px solid red;");
}
// ui->txtTitle_2->setText(QString::fromStdString(myItem.getTitle()));
// ui->txtAvailable_2->setText((QString&)myItem.getStatus());
// ui->txtFormat_2->setText((QString&) myItem.getFormat());

item::~item()
{
    delete ui;
}
