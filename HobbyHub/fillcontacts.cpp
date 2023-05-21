#include "fillcontacts.h"
#include "ui_fillcontacts.h"

FillContacts::FillContacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillContacts)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

FillContacts::~FillContacts()
{
    delete ui;
}

void FillContacts::on_BtnSaveContacts_clicked()
{

    this->close();
}
