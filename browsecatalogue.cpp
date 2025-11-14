#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
//#include "ui_catalogueitem.h"

BrowseCatalogue::BrowseCatalogue(QWidget *parent, Catalogue catalogue): QMainWindow(parent), ui(new Ui::BrowseCatalogue), catalogue(catalogue)
{
    ui->setupUi(this);

    // New widget and layout that will hold all subwidgets (item views)
    QWidget* widget = new QWidget();
    QVBoxLayout* box = new QVBoxLayout(widget);
    widget->setLayout(box);
    ui->scrollArea->ensureWidgetVisible(widget);

    // Go through every catalogue item, and add it to the view and to a list
    for (int i = 0; i < catalogue.getItemList().size(); i++){
        item* ofItem = new item(widget, catalogue.getItemList().at(i));
        // Boxes get cutoff if you don't set size policy to minimum
        ofItem->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        box->addWidget(ofItem);
        this->itemSubList.push_back(ofItem);
    }

    // Need to adjustSize of the widget (Container in the scrollArea) so that we can have a scroll view
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

