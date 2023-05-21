#ifndef FILLCONTACTS_H
#define FILLCONTACTS_H

#include <QDialog>

namespace Ui {
class FillContacts;
}

class FillContacts : public QDialog
{
    Q_OBJECT

public:
    explicit FillContacts(QWidget *parent = nullptr);
    ~FillContacts();

private slots:
    void on_BtnSaveContacts_clicked();

private:
    Ui::FillContacts *ui;
};

#endif // FILLCONTACTS_H
