#ifndef MAPPAGE_H
#define MAPPAGE_H

#include <QDialog>

namespace Ui {
class MapPage;
}

class MapPage : public QDialog
{
    Q_OBJECT

public:
    explicit MapPage(QWidget *parent = nullptr);
    ~MapPage();

private:
    Ui::MapPage *ui;
};

#endif // MAPPAGE_H
