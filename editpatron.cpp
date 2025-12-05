#include "editpatron.h"
#include "qlabel.h"
#include "ui_editpatron.h"
#include "qboxlayout.h"
#include "qdatetime.h"

EditPatron::EditPatron(QWidget *parent, Patron patron)
    : QDialog(parent)
    , ui(new Ui::EditPatron)
{
    ui->setupUi(this);
    loadData(patron);
    QWidget* allofthem = new QWidget();
    QVBoxLayout* allLoans = new QVBoxLayout();

    for (int i = 0; i < patron.getLoansSize(); i++){
        QHBoxLayout* allVals = new QHBoxLayout();
        QLabel* title = new QLabel();
        QLabel* dayRemain = new QLabel();
        title->setText(QString::fromStdString(patron.getLoans().at(i).getTitle()));

        QDateTime dueDate = QDateTime::fromSecsSinceEpoch(patron.getLoans().at(i).getDueDate().tm_sec);
        dayRemain->setText(dueDate.toString());

        allVals->addWidget(title); //allVals->addWidget(dayRemain);
        allLoans->addLayout(allVals);
    }
    allofthem->setLayout(allLoans);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(allofthem);
    setLayout(layout);
    this->setVisible(true);
}

EditPatron::~EditPatron()
{
    delete ui;
}

void EditPatron::loadData(Patron& patron){
    QSqlQuery query("SELECT item_id FROM loans WHERE patron_id = ?");
    query.addBindValue(patron.getId());
    query.exec();
    while (query.next()){
        int iid = query.value(0).toInt();

        // Creates new time, need to fix to get old time
        QSqlQuery query2;
        query2.prepare("SELECT * FROM catalogue WHERE cid = ?");
        query2.addBindValue(iid);
        query2.exec();
        while (query2.next()){
            std::string title = query2.value("title").toString().toStdString();
            std::string format = query2.value("format").toString().toStdString();
            std::string condition = query2.value("condition").toString().toStdString();
            std::string author = query2.value("author").toString().toStdString();
            int publishYear = query2.value("publish_year").toInt();
            int quantity = query2.value("quantity").toInt();
            int cid = query2.value("cid").toInt();
            CatalogueItem item = CatalogueItem(cid, title, author, publishYear, condition, format, quantity);
            Loan loan = Loan(item, tm());
            patron.addLoan(loan);
        }
    }
}
