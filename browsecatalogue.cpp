#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include "ui_catalogueitem.h"
#include "item.h"

BrowseCatalogue::BrowseCatalogue(QWidget *parent, Catalogue catalogue): QMainWindow(parent), ui(new Ui::BrowseCatalogue), catalogue(catalogue)
{
    ui->setupUi(this);
    // QWidget *centre = new QWidget(ui->centralwidget);
    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    for (int i = 0; i < catalogue.getItemList().size(); i++){
        item* ofItem = new item(ui->centralwidget, catalogue.getItemList().at(i));
        layout->addWidget(ofItem);
    }
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}

BrowseCatalogue::~BrowseCatalogue()
{
    delete ui;   
}
