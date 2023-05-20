#include "match.h"
#include "ui_match.h"

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
