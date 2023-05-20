#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QDialog>
#include <QCryptographicHash>
#include "client_manager.hpp"

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationPage(QWidget *parent,  ClientManager&&);
    ~RegistrationPage();

private slots:
    void on_BtnRegister_clicked();

    void on_login_editingFinished();

    void on_password_editingFinished();

private:
    Ui::RegistrationPage *ui;
    ClientManager clientManager;
};

#endif // REGISTRATIONPAGE_H
