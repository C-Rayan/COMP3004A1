#include "editcatalogue.h"
#include "viewstatus.h"
#include "ui_editcatalogue.h"

EditCatalogue::EditCatalogue(QWidget *parent, Librarian* l) :
    QWidget(parent), lib(*l),
    ui(new Ui::EditCatalogue)
{
    ui->setupUi(this);
    qRegisterMetaType<Patron>("Patron");
    loadData();
}


void EditCatalogue::loadData(){
    //Loads patrons  into combobox
    for(Patron p: lib.getClients()){
        ui->clientCcomboBox->addItem(QString::fromStdString(p.getName()), QVariant::fromValue(p));
    }

    //New wigdget  and layoout that will hold all the subwidgets
    QWidget* catalogueWidget = new QWidget();
    QVBoxLayout* layoutBox = new QVBoxLayout(catalogueWidget);
    catalogueWidget->setLayout(layoutBox);
    ui->scrollArea->ensureWidgetVisible(catalogueWidget);
    Catalogue& catalogue = lib.getCatalogue();


    // Go through every catalogue item, and add it to the view and to a list
    for (int i = 0; i < catalogue.getItemList().size(); i++){
        ViewRemoveItem* ofItem = new ViewRemoveItem(catalogueWidget, catalogue.getItemList().at(i));
        // Boxes get cutoff if you don't set size policy to minimum
        ofItem->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        layoutBox->addWidget(ofItem);
        this->itemList.push_back(ofItem);
    }
    layoutBox->addStretch();
    ui->scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(catalogueWidget);
}

EditCatalogue::~EditCatalogue()
{
    delete ui;
}



void EditCatalogue::on_searchButton_clicked()
{
    Patron patron = ui->clientCcomboBox->currentData().value<Patron>();
    viewStatus *statusMenu =new viewStatus(this,  &patron );
    statusMenu->setWindowFlags(Qt::Window);
    statusMenu->show();
;}


