#include "lifestylechoices.h"
#include "ui_lifestylechoices.h"

LifeStyleChoices::LifeStyleChoices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LifeStyleChoices)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

LifeStyleChoices::~LifeStyleChoices()
{
    delete ui;
}

void LifeStyleChoices::on_pushButton_clicked()
{
    this->close();
}
