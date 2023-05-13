#ifndef TESTS_H
#define TESTS_H
#include <QObject>
#include <QWidget>

class Test_QLineEdit : public QObject
{
    Q_OBJECT
private slots: // должны быть приватными
    void testEditPasswordLineOnGP();
    void testEditLoginLineOnGP();
};

class Test_QPushButton : public QObject
{
    Q_OBJECT
private slots: // должны быть приватными
    void testButtonClick();
    void testOpeningRegistartionFromGP();
    void testOpeningMyAccountFromGP();
    void testButtonPress();
};

class TestMainWindow : public QObject
{
    Q_OBJECT

private slots:
    void testTitle();
    void testCentralWidget();
};



#endif // TESTS_H
