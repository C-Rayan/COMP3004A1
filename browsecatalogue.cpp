#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include "viewstatus.h"

BrowseCatalogue::BrowseCatalogue(QWidget *parent, Catalogue catalogue): QMainWindow(parent), ui(new Ui::BrowseCatalogue), catalogue(catalogue)
{
    ui->setupUi(this);

    QWidget* widget = new QWidget();
    QVBoxLayout* box = new QVBoxLayout(widget);
    widget->setLayout(box);
    ui->scrollArea->ensureWidgetVisible(widget);

    for (int i = 0; i < catalogue.getItemList().size(); i++){
        item* ofItem = new item(widget, catalogue.getItemList().at(i));
        ofItem->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        box->addWidget(ofItem);
        //QObject::connect(ofItem, &item::onLoanState, this, &BrowseCatalogue::getSomeItem);
        this->itemSubList.push_back(ofItem);
    }

    widget->adjustSize();
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(widget);
}

BrowseCatalogue::~BrowseCatalogue()
{
    delete ui;
}


void BrowseCatalogue::getSomeItem(){
    emit someHappened();
}


void BrowseCatalogue::on_pushButton_clicked()
{


}

