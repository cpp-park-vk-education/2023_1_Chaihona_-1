#include "editmydata.h"
#include "ui_editmydata.h"

EditMyData::EditMyData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditMyData)
{
    ui->setupUi(this);
}

EditMyData::~EditMyData()
{
    delete ui;
}
