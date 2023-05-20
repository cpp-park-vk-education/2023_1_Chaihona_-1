#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <QDialog>
#include "connection.h"
#include <cstdio>
#include "greetingpage.h"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv); //запуск приложения
    GreetingPage w;

    if (!createConnection())
        return 1;


    w.show();
    return a.exec();

}

