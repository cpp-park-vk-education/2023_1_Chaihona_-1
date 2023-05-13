#include "match.h"
#include "ui_match.h"

match::match(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::match)
{
    ui->setupUi(this);
}

match::~match()
{
    delete ui;
}
