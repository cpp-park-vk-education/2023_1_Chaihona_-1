#ifndef FILLINGDATAPAGE_H
#define FILLINGDATAPAGE_H
#include "registrationpage.h"
#include <QDialog>
#include <QListWidgetItem>
#include "client_manager.hpp"
#include "QMessageBox"
namespace Ui {
class FillingDataPage;
}

class FillingDataPage : public QDialog
{
    Q_OBJECT

public:
    explicit FillingDataPage(QWidget *parent, ClientManager&&);
    ~FillingDataPage();

private slots:

    void on_BtnConfirm_clicked();

    void on_name_editingFinished();


    void on_city_editingFinished();

    void on_login_editingFinished();

    void on_interests_itemDoubleClicked(QListWidgetItem *item);

private:
    std::vector<Interest> possibleInterests;
    Ui::FillingDataPage *ui;
    ClientManager clientManager;
};

#endif
