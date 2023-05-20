#include "myaccount.h"
#include "ui_myaccount.h"
#include "meetingpage.h"
#include "greetingpage.h"
#include "QDebug"
#include "listofmathes.h"

#include "fillingdatapage.h"


MyAccount::MyAccount(QWidget *parent, ClientManager&& _cm) :
    QDialog(parent),
    ui(new Ui::MyAccount),
    clientManager(std::move(_cm))
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

MyAccount::~MyAccount()
{
    delete ui;
}

void MyAccount::on_BtnToMeetingPage_clicked()
{
    hide();
    MeetingPage window (nullptr, std::move(clientManager));
    window.setModal(true);
    window.exec();
}



void MyAccount::on_LogOut_clicked()
{
    hide();
    this->close();
    GreetingPage window (nullptr, std::move(clientManager));
}

void MyAccount::on_BtnToMyMatches_clicked()
{
    ListOfMathes window;
    window.setModal(true);
    window.exec();
}

void MyAccount::on_BtnEdit_clicked()
{
    FillingDataPage window(nullptr, std::move(clientManager));
    window.setModal(true);
    window.exec();
}
