#ifndef MATCH_H
#define MATCH_H

#include <QDialog>

namespace Ui {
class match;
}

class match : public QDialog
{
    Q_OBJECT

public:
    explicit match(QWidget *parent = nullptr);
    ~match();

private:
    Ui::match *ui;
};

#endif // MATCH_H
