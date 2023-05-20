#include "registrationpage.h"
#include "ui_registrationpage.h"
#include "myaccount.h"
#include "fillingdatapage.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
// #include "client_manager.hpp"

RegistrationPage::RegistrationPage(QWidget *parent, ClientManager &&_cm) : QDialog(parent),
                                                                           ui(new Ui::RegistrationPage),
                                                                           clientManager(std::move(_cm))
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
    if (clientManager.login_check(ui->login->text().toStdString())) {
        QMessageBox loginBusy (this);
        loginBusy.setGeometry(860,600, 300, 100);
        loginBusy.critical(0,"Error","This login is busy!");
        loginBusy.setGeometry(860,600, 300, 100);
        loginBusy.show();
        loginBusy.setGeometry(860,600, 300, 100);
    }
    else {
        clientManager.registration(ui->login->text().toStdString(), ui->password->text().toStdString());
        hide();
        // clientManager.registration(ui->login->text().toStdString(), ui->password->text().toStdString());
        FillingDataPage window(nullptr, std::move(clientManager));
        window.setModal(true);
        window.exec();
    }
}

void RegistrationPage::on_login_editingFinished()
{
    qDebug() << ui->login->text();
}

void RegistrationPage::on_password_editingFinished()
{

    QString pass = ui->password->text();
    QByteArray arrpass = pass.toUtf8();
    QString hashpass = QString(QCryptographicHash::hash((arrpass), QCryptographicHash::Md5).toHex());
    qDebug() << hashpass;
}
