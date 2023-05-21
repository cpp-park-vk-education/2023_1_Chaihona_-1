#include "lifestyle.h"
#include "ui_lifestyle.h"

Lifestyle::Lifestyle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lifestyle)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

Lifestyle::~Lifestyle()
{
    delete ui;
}
