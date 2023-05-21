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
    this->setStyleSheet("background-color: moccasin;");
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

void RegistrationPage::on_login_editingFinished()
{
        qDebug() << ui->login->text();
        qDebug() << " as" ;
}

void RegistrationPage::on_password_editingFinished()
{

        QString pass = ui->password->text();
        QByteArray arrpass = pass.toUtf8();
        QString hashpass = QString(QCryptographicHash::hash((arrpass),QCryptographicHash::Md5).toHex());
        qDebug() << hashpass;
}
