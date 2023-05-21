#ifndef LIFESTYLE_H
#define LIFESTYLE_H

#include <QDialog>

namespace Ui {
class Lifestyle;
}

class Lifestyle : public QDialog
{
    Q_OBJECT

public:
    explicit Lifestyle(QWidget *parent = nullptr);
    ~Lifestyle();

private:
    Ui::Lifestyle *ui;
};

#endif // LIFESTYLE_H
