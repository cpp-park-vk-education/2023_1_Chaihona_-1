#include "mappage.h"
#include "ui_mappage.h"

MapPage::MapPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

MapPage::~MapPage()
{
    delete ui;
}
