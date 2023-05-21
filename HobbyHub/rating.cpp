#include "rating.h"
#include "ui_rating.h"

Rating::Rating(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rating)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

Rating::~Rating()
{
    delete ui;
}

void Rating::on_BtnSaveRating_clicked()
{
    this->close();

}
