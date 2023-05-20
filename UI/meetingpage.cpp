#include "meetingpage.h"
#include "ui_meetingpage.h"
#include "myaccount.h"

MeetingPage::MeetingPage(QWidget *parent, ClientManager&& _cm) :
    QDialog(parent),
    ui(new Ui::MeetingPage),
    clientManager(std::move(_cm))
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
}

MeetingPage::~MeetingPage()
{
    delete ui;
}

void MeetingPage::on_BactToAcc_clicked()
{
    hide();
    MyAccount window (nullptr, std::move(clientManager));
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
