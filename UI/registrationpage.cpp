#include "registrationpage.h"
#include "ui_registrationpage.h"
#include "myaccount.h"
#include "fillingdatapage.h"
#include <QDebug>
#include <iostream>
//#include "client_manager.hpp"


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

void RegistrationPage::on_BtnRegister_clicked()
{
    hide();
    //clientManager.registration(ui->login->text().toStdString(), ui->password->text().toStdString());
    FillingDataPage window;
    window.setModal(true);
    window.exec();
}

void RegistrationPage::on_email_editingFinished()
{
        qDebug() << ui->email->text();
}

void RegistrationPage::on_password_editingFinished()
{
        qDebug() << ui->password->text();
}
