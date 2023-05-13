#include "registrationpage.h"
#include "ui_registrationpage.h"
#include "myaccount.h"

RegistrationPage::RegistrationPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationPage)
{
    ui->setupUi(this);
}

RegistrationPage::~RegistrationPage()
{
    delete ui;
}



void RegistrationPage::on_BtnConfirm_clicked()
{
    hide();
    MyAccount window;
    window.setModal(true);
    window.exec();
}

void RegistrationPage::on_name_editingFinished()
{

}

void RegistrationPage::on_age_editingFinished()
{

}

void RegistrationPage::on_city_editingFinished()
{

}

void RegistrationPage::on_email_editingFinished()
{

}

void RegistrationPage::on_interests_itemClicked(QListWidgetItem *item)
{

}

