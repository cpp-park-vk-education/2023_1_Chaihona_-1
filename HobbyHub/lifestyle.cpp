#include "lifestyle.h"
#include "ui_lifestyle.h"
#include "rating.h"

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

void Lifestyle::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Rating window;
    window.setModal(true);
    window.exec();
}
