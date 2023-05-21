#ifndef FILLINGDATAPAGE_H
#define FILLINGDATAPAGE_H
#include "registrationpage.h"
#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class FillingDataPage;
}

class FillingDataPage : public QDialog
{
    Q_OBJECT

public:
    explicit FillingDataPage(QWidget *parent = nullptr);
    ~FillingDataPage();

private slots:

    void on_BtnConfirm_clicked();

    void on_name_editingFinished();


    void on_city_editingFinished();

    void on_login_editingFinished();

    void on_interests_itemDoubleClicked(QListWidgetItem *item);

    void on_BtnChooseLocation_clicked();

    void on_BtnFillContacts_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::FillingDataPage *ui;
};

#endif
