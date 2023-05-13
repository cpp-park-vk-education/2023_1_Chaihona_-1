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

private:
    Ui::ListOfMathes *ui;
};

#endif // LISTOFMATHES_H
