#include "fillingdatapage.h"
#include "ui_fillingdatapage.h"
#include "myaccount.h"
#include "greetingpage.h"

FillingDataPage::FillingDataPage(QWidget *parent, ClientManager&& _cm) :
    QDialog(parent),
    ui(new Ui::FillingDataPage),
    clientManager(std::move(_cm))
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: moccasin;");
    possibleInterests = clientManager.GetPossibleInterest();
    for (size_t i = 0; i < possibleInterests.size(); i++) {
        QListWidgetItem *newItem = new QListWidgetItem;
        QVariant v;
        v.setValue(i);
        newItem->setData(Qt::UserRole, v);
        newItem->setText(QString::fromStdString(possibleInterests[i].getName()));
        ui->interests->addItem(newItem);
    }
}

FillingDataPage::~FillingDataPage()
{
    delete ui;
}



void FillingDataPage::on_BtnConfirm_clicked()
{
    hide();
    MyAccount window(nullptr, std::move(clientManager));
    window.setModal(true);
    window.exec();
}

void FillingDataPage::on_name_editingFinished()
{

}


void FillingDataPage::on_city_editingFinished()
{

}

void FillingDataPage::on_login_editingFinished()
{

}


void FillingDataPage::on_interests_itemDoubleClicked(QListWidgetItem *item) {
    QVariant v = item->data(Qt::UserRole);
    unsigned idx = v.value<unsigned>();
    QMessageBox loginBusy (this);

    loginBusy.critical(0,QString::fromStdString(possibleInterests[idx].getName()), QString::fromStdString(possibleInterests[idx].getDescription()));
    loginBusy.show();
}
