#include "greetingpage.h"
#include "ui_greetingpage.h"
#include "fillingdatapage.h"
#include "myaccount.h"
#include "qDebug"
#include "registrationpage.h"
#include <QDialog>
#include "meetingpage.h"
#include "forgotpassword.h"

#include "ui_meetingpage.h"


GreetingPage::GreetingPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GreetingPage)
{
    ui->setupUi(this);
}

GreetingPage::~GreetingPage()
{
    delete ui;
}


void GreetingPage::on_BtnLogIn_clicked()
{
    //clientManager.log_in(ui->login->text().toStdString(), ui->password->text().toStdString());

    MyAccount window;
    window.setModal(true);
    window.exec();
}

void GreetingPage::on_BtnRegister_clicked()
{
    hide();
    RegistrationPage window;
    window.setModal(true);
    window.exec();
}

void GreetingPage::on_login_editingFinished()
{
    qDebug() << ui->login->text();
}

void GreetingPage::on_password_editingFinished()
{

    qDebug() << ui->password->text();
}


void GreetingPage::on_BtnForgottenPass_clicked()
{
    hide();
    ForgotPassword window;
    window.setModal(true);
    window.exec();
}


//геттеры длля тестов (в UML не включены)
QLineEdit *GreetingPage::GetPass(){
    return ui->password;
}

QLineEdit *GreetingPage::GetLog(){
    return ui->login;
}

QPushButton *GreetingPage::GetRegisterPushButton(){
    return ui->BtnRegister;
}

QPushButton *GreetingPage::GetMyAccountPushButton(){
    return ui->BtnLogIn;
}


QLabel *GreetingPage::GetLabel(){
    return ui->RegLabel;
}

