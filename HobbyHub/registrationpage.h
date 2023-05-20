#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QDialog>
#include <QCryptographicHash>

namespace Ui {
class RegistrationPage;
}

class RegistrationPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationPage(QWidget *parent = nullptr);
    ~RegistrationPage();

private slots:
    void on_BtnRegister_clicked();

    void on_login_editingFinished();

    void on_password_editingFinished();

private:
    Ui::RegistrationPage *ui;
};

#endif // REGISTRATIONPAGE_H
