#ifndef LIFESTYLECHOICES_H
#define LIFESTYLECHOICES_H

#include <QDialog>

namespace Ui {
class LifeStyleChoices;
}

class LifeStyleChoices : public QDialog
{
    Q_OBJECT

public:
    explicit LifeStyleChoices(QWidget *parent = nullptr);
    ~LifeStyleChoices();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LifeStyleChoices *ui;
};

#endif // LIFESTYLECHOICES_H
