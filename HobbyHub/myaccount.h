#ifndef MYACCOUNT_H
#define MYACCOUNT_H

#include <QDialog>

namespace Ui {
class MyAccount;
}

class MyAccount : public QDialog
{
    Q_OBJECT

public:
    explicit MyAccount(QWidget *parent = nullptr);
    ~MyAccount();

private slots:
    void on_BtnToMeetingPage_clicked();

    void on_LogOut_clicked();

    void on_BtnToMyMatches_clicked();

    void on_BtnEdit_clicked();

private:
    Ui::MyAccount *ui;
};

#endif // MYACCOUNT_H
