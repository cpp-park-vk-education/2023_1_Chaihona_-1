#include <QApplication>
#include <QTest>
#include <iostream>
#include <cstdlib>
#include <QDialog>

#include <cstdio>
#include "tests.h"
#include "greetingpage.h"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv); //запуск приложения
    GreetingPage w;
    w.show();
    return a.exec();

}

