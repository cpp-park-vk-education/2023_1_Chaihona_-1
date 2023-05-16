#include <QtTest>
#include <QtGui>
#include "tests.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "greetingpage.h"
#include "myaccount.h"
#include <QMainWindow>

void Test_QLineEdit::testEditPasswordLineOnGP()
{
    GreetingPage greetingpage;
    QLineEdit *a = greetingpage.GetPass();
    QTest::keyClicks(a, "mypassword123");
    QCOMPARE(a->text(), QString("mypassword123"));
    QVERIFY(a->isModified());

}


void Test_QLineEdit::testEditLoginLineOnGP() // GP = Greeting Page
{
    GreetingPage greetingpage;
    QLineEdit *a = greetingpage.GetLog();
    QTest::keyClicks(a, "mylogin123");
    QCOMPARE(a->text(), QString("mylogin123"));
    QVERIFY(a->isModified());
}


void  Test_QPushButton::testOpeningRegistartionFromGP()
    {

        GreetingPage greetingpage;
        QPushButton *btn = greetingpage.GetRegisterPushButton();// создаем кнопку
        QWidget RegPage;
        QObject::connect(btn, &QPushButton::clicked, &RegPage, &MyAccount::show);
        QTest::mouseClick(btn, Qt::LeftButton);
        QVERIFY2(RegPage.isVisible(), "Ошибка: окно регистрации не открылось.");

}

void  Test_QPushButton::testOpeningMyAccountFromGP()
    {

        GreetingPage greetingpage;
        QPushButton *btn = greetingpage.GetMyAccountPushButton();// создаем кнопку
        QWidget MyAcc;
        QObject::connect(btn, &QPushButton::clicked, &MyAcc, &MyAccount::show);
        QTest::mouseClick(btn, Qt::LeftButton);
        QVERIFY2(MyAcc.isVisible(), "Ошибка: окно регистрации не открылось.");

}


void TestMainWindow::testTitle()
    {
        GreetingPage greetingpage;
        greetingpage.setWindowTitle("GreetingPage");
        QCOMPARE(greetingpage.windowTitle(), QString("GreetingPage"));

    }

void TestMainWindow::testCentralWidget()
    {
        GreetingPage greetingpage;
        QMainWindow mainWindow;
        QLabel *label = greetingpage.GetLabel();
        greetingpage.setCentralWidget(label);
        QCOMPARE(greetingpage.centralWidget(), label);
    }

void  Test_QPushButton::testButtonClick()
    {
      /*  GreetingPage gp;
        QPushButton *a = gp.GetPushButton();// создаем кнопку

        // проверяем, что кнопка не нажата
        QCOMPARE(a->isDown(), false);

        // эмулируем нажатие кнопки
        QTest::mouseClick(a, Qt::RightButton);
        // проверяем, что кнопка нажата
        QCOMPARE(a->isDown(), true);
        */
}


void Test_QPushButton::testButtonPress()
    {/*
        // Создаем главное окно
        QMainWindow main_window;

        // Создаем кнопку
        QPushButton button("Открыть новое окно", &main_window);

        // Создаем новое окно
        QWidget new_window;

        // Соединяем сигнал нажатия кнопки со слотом открытия нового окна
        QObject::connect(&button, &QPushButton::clicked, &new_window, &QWidget::show);

        // Имитируем нажатие кнопки
        QTest::mouseClick(&button, Qt::LeftButton);

        // Проверяем, что новое окно открылось
        QVERIFY2(new_window.isVisible(), "Ошибка: новое окно не открылось.");
        */
    }


