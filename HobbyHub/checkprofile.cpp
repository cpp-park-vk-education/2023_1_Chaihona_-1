#include "checkprofile.h"
#include "ui_checkprofile.h"

CheckProfile::CheckProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckProfile)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

CheckProfile::~CheckProfile()
{
    delete ui;
}

