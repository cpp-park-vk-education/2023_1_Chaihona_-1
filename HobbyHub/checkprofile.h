#ifndef CHECKPROFILE_H
#define CHECKPROFILE_H

#include <QDialog>

namespace Ui {
class CheckProfile;
}

class CheckProfile : public QDialog
{
    Q_OBJECT

public:
    explicit CheckProfile(QWidget *parent = nullptr);
    ~CheckProfile();

private slots:

private:
    Ui::CheckProfile *ui;
};

#endif // CHECKPROFILE_H
