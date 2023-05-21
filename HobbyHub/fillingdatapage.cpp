#include "fillingdatapage.h"
#include "ui_fillingdatapage.h"
#include "myaccount.h"
#include "greetingpage.h"
#include "mappage.h"
#include "lifestyle.h"
#include "fillcontacts.h"

FillingDataPage::FillingDataPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FillingDataPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
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

void FillingDataPage::on_login_editingFinished()
{

}


void FillingDataPage::on_interests_itemDoubleClicked(QListWidgetItem *item)
{

}

void FillingDataPage::on_BtnChooseLocation_clicked()
{
    MapPage window;
    window.setModal(true);
    window.exec();
}


void FillingDataPage::on_BtnChooseLifestyle_clicked()
{
    Lifestyle window;
    window.setModal(true);
    window.exec();
}

void FillingDataPage::on_BtnFillContacts_clicked()
{
    FillContacts window;
    window.setModal(true);
    window.exec();
}
