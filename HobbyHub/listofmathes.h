#ifndef LISTOFMATHES_H
#define LISTOFMATHES_H

#include <QDialog>

namespace Ui {
class ListOfMathes;
}

class ListOfMathes : public QDialog
{
    Q_OBJECT

public:
    explicit ListOfMathes(QWidget *parent = nullptr);
    ~ListOfMathes();

private slots:
    void on_BtnBackToAcc_clicked();

    void on_BtnCheckProfile_clicked();

private:
    Ui::ListOfMathes *ui;
};

#endif // LISTOFMATHES_H
