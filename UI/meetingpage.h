#ifndef MEETINGPAGE_H
#define MEETINGPAGE_H

#include <QDialog>
#include "client_manager.hpp"

namespace Ui {
class MeetingPage;
}

class MeetingPage : public QDialog
{
    Q_OBJECT

public:
    explicit MeetingPage(QWidget *parent, ClientManager&&);
    ~MeetingPage();

private slots:
    void on_BactToAcc_clicked();

    void on_Dislike_clicked();

    void on_Like_clicked();

    void on_MoreInfo_clicked();

private:
    Ui::MeetingPage *ui;
    ClientManager clientManager;
};

#endif // MEETINGPAGE_H
