#include "viewaccountstatus.h"
#include "ui_viewaccountstatus.h"

viewAccountStatus::viewAccountStatus(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewAccountStatus)
{
    ui->setupUi(this);
}

viewAccountStatus::~viewAccountStatus()
{
    delete ui;
}
