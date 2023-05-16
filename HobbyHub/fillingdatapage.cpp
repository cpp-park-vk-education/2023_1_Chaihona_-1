#include "fillingdatapage.h"
#include "ui_fillingdatapage.h"
#include "myaccount.h"
#include "greetingpage.h"

FillingDataPage::FillingDataPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillingDataPage)
{
    ui->setupUi(this);
}

FillingDataPage::~FillingDataPage()
{
    delete ui;
}



void FillingDataPage::on_BtnConfirm_clicked()
{
    hide();
    MyAccount window;
    window.setModal(true);
    window.exec();
}

void FillingDataPage::on_name_editingFinished()
{

}


void FillingDataPage::on_city_editingFinished()
{

}

void FillingDataPage::on_email_editingFinished()
{

}


void FillingDataPage::on_interests_itemDoubleClicked(QListWidgetItem *item)
{

}
