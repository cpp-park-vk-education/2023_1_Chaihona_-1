#include "meetingpage.h"
#include "ui_meetingpage.h"
#include "myaccount.h"

MeetingPage::MeetingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MeetingPage)
{
    ui->setupUi(this);
}

MeetingPage::~MeetingPage()
{
    delete ui;
}

void MeetingPage::on_BactToAcc_clicked()
{
    hide();
    MyAccount window;
    window.setModal(true);
    window.exec();
}

void MeetingPage::on_Dislike_clicked()
{

}

void MeetingPage::on_Like_clicked()
{

}

void MeetingPage::on_MoreInfo_clicked()
{

}
