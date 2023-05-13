#include "listofmathes.h"
#include "ui_listofmathes.h"

ListOfMathes::ListOfMathes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfMathes)
{
    ui->setupUi(this);
}

ListOfMathes::~ListOfMathes()
{
    delete ui;
}
