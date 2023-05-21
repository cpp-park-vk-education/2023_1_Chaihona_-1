#ifndef RATING_H
#define RATING_H

#include <QDialog>

namespace Ui {
class Rating;
}

class Rating : public QDialog
{
    Q_OBJECT

public:
    explicit Rating(QWidget *parent = nullptr);
    ~Rating();

private slots:
    void on_BtnSaveRating_clicked();

private:
    Ui::Rating *ui;
};

#endif // RATING_H
