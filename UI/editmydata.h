#ifndef EDITMYDATA_H
#define EDITMYDATA_H

#include <QDialog>

namespace Ui {
class EditMyData;
}

class EditMyData : public QDialog
{
    Q_OBJECT

public:
    explicit EditMyData(QWidget *parent = nullptr);
    ~EditMyData();

private:
    Ui::EditMyData *ui;
};

#endif // EDITMYDATA_H
