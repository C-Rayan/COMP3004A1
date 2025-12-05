#include "viewremoveitem.h"
#include "ui_viewremoveitem.h"

ViewRemoveItem::ViewRemoveItem(QWidget *parent, const CatalogueItem& ci) : QWidget(parent), item(ci), ui(new Ui::ViewRemoveItem){
    ui->setupUi(this);
    ui->txtTitle->setText(QString::fromStdString(item.getTitle()));
    ui->txtAuthor->setText(QString::fromStdString(item.getAuthor()));
    ui->txtFormat->setText(QString::fromStdString(item.getFormat()));
    ui->txtAvailable->setText(QString::fromStdString(item.getStatus()));

}

ViewRemoveItem::~ViewRemoveItem()
{
    delete ui;
}

void ViewRemoveItem::on_removeItemButton_clicked()
{
    emit offRemoveItem();
}

