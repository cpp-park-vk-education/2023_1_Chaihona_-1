#include "greetingpage.h"
#include "ui_greetingpage.h"
#include "fillingdatapage.h"
#include "myaccount.h"
// #include "qDebug"
#include "registrationpage.h"
#include <QDialog>
#include "meetingpage.h"
#include "forgotpassword.h"

#include "ui_meetingpage.h"

GreetingPage::GreetingPage(QWidget *parent, ClientManager &&_cm)
    : QMainWindow(parent), ui(new Ui::GreetingPage),
      clientManager(std::move(_cm))
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: moccasin;");
}

GreetingPage::~GreetingPage()
{
    delete ui;
}

void GreetingPage::on_BtnLogIn_clicked()
{
    auto userProfile = clientManager.log_in(ui->login->text().toStdString(), ui->password->text().toStdString());
    if (userProfile) {
        MyAccount window(nullptr, std::move(clientManager));
        window.setModal(true);
        window.exec();
    } else {
        QMessageBox loginBusy (this);
        loginBusy.critical(0,"Error", "Wrong login or password");
        loginBusy.show();
    }
}

void GreetingPage::on_BtnRegister_clicked()
{
    hide();
    RegistrationPage window(nullptr, std::move(clientManager));
    window.setModal(true);
    window.exec();
}

void GreetingPage::on_login_editingFinished()
{
    qDebug() << ui->login->text();
}

void GreetingPage::on_password_editingFinished()
{
    QString pass = ui->password->text();
    QByteArray arrpass = pass.toUtf8();
    QString hashpass = QString(QCryptographicHash::hash((arrpass), QCryptographicHash::Md5).toHex());
    qDebug() << hashpass;
}

void GreetingPage::on_BtnForgottenPass_clicked()
{
    hide();
    ForgotPassword window;
    window.setModal(true);
    window.exec();
}

// геттеры длля тестов (в UML не включены)
QLineEdit *GreetingPage::GetPass()
{
    return ui->password;
}

QLineEdit *GreetingPage::GetLog()
{
    return ui->login;
}

QPushButton *GreetingPage::GetRegisterPushButton()
{
    return ui->BtnRegister;
}

QPushButton *GreetingPage::GetMyAccountPushButton()
{
    return ui->BtnLogIn;
}

QLabel *GreetingPage::GetLabel()
{
    return ui->RegLabel;
}
