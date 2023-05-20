#ifndef GREETINGPAGE_H
#define GREETINGPAGE_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QCryptographicHash>
#include <QLineEdit>
#include "client_manager.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class GreetingPage; }
QT_END_NAMESPACE

class GreetingPage : public QMainWindow
{
    Q_OBJECT

public:
    GreetingPage(QWidget *parent, ClientManager&&);
    ~GreetingPage();
     QLineEdit *GetPass();
     QLineEdit *GetLog();
     QPushButton *GetRegisterPushButton();
     QPushButton *GetMyAccountPushButton();
     QLabel *GetLabel();

private slots:

    void on_BtnLogIn_clicked();

    void on_BtnRegister_clicked();

    void on_login_editingFinished();

    void on_password_editingFinished();

    void on_BtnForgottenPass_clicked();

private:
    Ui::GreetingPage *ui;
    ClientManager clientManager;
};
#endif // GREETINGPAGE_H
