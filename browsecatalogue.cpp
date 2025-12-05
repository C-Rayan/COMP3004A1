#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"
#include "ui_viewauth.h"

BrowseCatalogue::BrowseCatalogue(QWidget *parent, Catalogue catalogue, Patron* patron): QMainWindow(parent), ui(new Ui::BrowseCatalogue), catalogue(catalogue), patron(patron)
{
    ui->setupUi(this);

    // New widget and layout that will hold all subwidgets (item views)
    QWidget* widget = new QWidget();
    QVBoxLayout* box = new QVBoxLayout(widget);
    widget->setLayout(box);
    ui->scrollArea->ensureWidgetVisible(widget);
\
    // D1 IMPLEMENTATION (For debugging)
    // We already have the items in our list at this point, no need to change or query DB (NOT CHANGING ANYTHING, ONLY CREATING INTIIAL LAYOUT)
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

void BrowseCatalogue::on_accountButton_clicked()
{
    viewStatus *statusMenu =new viewStatus(this,  patron);
    statusMenu->setWindowFlags(Qt::Window);
    statusMenu->show();
}

