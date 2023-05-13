#ifndef MEETINGPAGE_H
#define MEETINGPAGE_H

#include <QDialog>

namespace Ui {
class MeetingPage;
}

class MeetingPage : public QDialog
{
    Q_OBJECT

public:
    explicit MeetingPage(QWidget *parent = nullptr);
    ~MeetingPage();

private slots:
    void on_BactToAcc_clicked();

    void on_Dislike_clicked();

    void on_Like_clicked();

    void on_MoreInfo_clicked();

private:
    Ui::MeetingPage *ui;
};

#endif // MEETINGPAGE_H
