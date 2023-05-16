#include "myaccount.h"
#include "ui_myaccount.h"
#include "meetingpage.h"
#include "greetingpage.h"
#include "QDebug"
#include "listofmathes.h"
#include "editmydata.h"
#include "fillingdatapage.h"



MyAccount::MyAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyAccount)
{
    ui->setupUi(this);
}

MyAccount::~MyAccount()
{
    delete ui;
}

void MyAccount::on_BtnToMeetingPage_clicked()
{
    hide();
    MeetingPage window;
    window.setModal(true);
    window.exec();
}


void MyAccount::on_LogOut_clicked()
{
    hide();
    this->close();
    GreetingPage window;

}

void MyAccount::on_BtnToMyMatches_clicked()
{
    ListOfMathes window;
    window.setModal(true);
    window.exec();
}

void MyAccount::on_BtnEdit_clicked()
{
    FillingDataPage window;
    window.setModal(true);
    window.exec();
}
