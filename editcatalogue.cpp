#include "editcatalogue.h"
#include "editpatron.h"
#include "qdialog.h"
#include "qlineedit.h"
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


// When librarians want to manage a patron
void EditCatalogue::on_pushButton_clicked()
{
    QWidget* dialog = new QDialog();
    QVBoxLayout* box = new QVBoxLayout(dialog);
    dialog->setLayout(box);

    //QLineEdit* name = new QLineEdi;
    QLineEdit* name = new QLineEdit("Please enter patron's name", dialog);
    box->addWidget(name);
    QPushButton* button = new QPushButton();
    button->setText("View Patron");
    box->addWidget(button);
    dialog->setFixedSize(400, 400);
    dialog->setVisible(true);

    QObject::connect(button, &QPushButton::clicked, [name, dialog]{
        QSqlQuery query;
        query.prepare("SELECT * FROM PATRONS WHERE name = ?");
        query.addBindValue(name->text());
        query.exec();
        if (query.exec() != 0){
            if (query.next()){
                int id = query.value(0).toInt();
                std::string name = query.value(1).toString().toStdString();
                std::string email = query.value(2).toString().toStdString();
                int pin = query.value(3).toInt();
                int numLoans = query.value(4).toInt();
                Patron patron = Patron(id, name, email, pin, numLoans);
                dialog->setVisible(false);

                new EditPatron(nullptr, patron);
            }
        }
        else {
            std::cout << "Invalid Name" << query.exec() << std::endl;
        }
    });
}


