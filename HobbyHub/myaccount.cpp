#include "myaccount.h"
#include "ui_myaccount.h"
#include "meetingpage.h"
#include "greetingpage.h"
#include "QDebug"
#include "listofmathes.h"
#include "editmydata.h"



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
    qDebug() << "" ;
  //  GreetingPage windowq;
 // windowq.setModal(true);
//    wind.exec();
}

void MyAccount::on_BtnToMyMatches_clicked()
{
    ListOfMathes window;
    window.setModal(true);
    window.exec();
}

void MyAccount::on_BtnEdit_clicked()
{
    EditMyData window;
    window.setModal(true);
    window.exec();
}
