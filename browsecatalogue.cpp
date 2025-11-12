#include "browsecatalogue.h"
#include "ui_browsecatalogue.h"

BrowseCatalogue::BrowseCatalogue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BrowseCatalogue)
{
    ui->setupUi(this);
}

BrowseCatalogue::~BrowseCatalogue()
{
    delete ui;
}
