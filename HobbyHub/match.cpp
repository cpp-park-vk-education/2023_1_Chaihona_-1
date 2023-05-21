#include "match.h"
#include "ui_match.h"
#include "checkprofile.h"

match::match(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::match)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

match::~match()
{
    delete ui;
}

void match::on_BtnCheckProfile_clicked()
{
    this->close();
    CheckProfile window;
    window.setModal(true);
    window.exec();
}
