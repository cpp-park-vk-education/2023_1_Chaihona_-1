#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QDialog>
#include <QListWidgetItem>
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

    void on_BtnConfirm_clicked();

    void on_name_editingFinished();

    void on_age_editingFinished();

    void on_city_editingFinished();

    void on_email_editingFinished();

    void on_interests_itemClicked(QListWidgetItem *item);

    void on_interests_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::RegistrationPage *ui;
};

#endif // REGISTRATIONPAGE_H
