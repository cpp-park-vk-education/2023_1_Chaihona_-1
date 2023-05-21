#ifndef LIFESTYLE_H
#define LIFESTYLE_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Lifestyle;
}

class Lifestyle : public QDialog
{
    Q_OBJECT

public:
    explicit Lifestyle(QWidget *parent = nullptr);
    ~Lifestyle();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
private:
    Ui::Lifestyle *ui;
};

#endif // LIFESTYLE_H
