#include "listofmathes.h"
#include "ui_listofmathes.h"
#include "myaccount.h"
#include "checkprofile.h"

ListOfMathes::ListOfMathes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfMathes)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

ListOfMathes::~ListOfMathes()
{
    delete ui;
}

void ListOfMathes::on_BtnBackToAcc_clicked()
{
    this->close();
}

void ListOfMathes::on_BtnCheckProfile_clicked()
{
    this->close();
    CheckProfile window;
    window.setModal(true);
    window.exec();
}
