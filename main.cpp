#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <QDialog>

#include <cstdio>
#include "tests.h"
#include "greetingpage.h"
#include <boost/json/src.hpp>
#include "client_manager.hpp"
#include <thread>
#include <chrono>
#include <vector>


int main(int argc, char *argv[])
{

    //       freopen("testing.log", "w", stdout); // тесты к окну greetingpage
    //       QApplication a(argc, argv);
    //       QTest::qExec(new Test_QLineEdit, argc, argv);
    //       QTest::qExec(new Test_QPushButton, argc, argv);
    //       QTest::qExec(new TestMainWindow, argc, argv);
    //       return 0;

    auto const host = "127.0.0.1";
    auto const port = "7778";
    // auto const host = "8.8.8.8";
    // auto const port = "80";
    auto const text = "lol";

    // The io_context is required for all I/O
    net::io_context ioc;

    // Launch the asynchronous operation
    auto client_ptr = std::make_shared<Client>(ioc);
    client_ptr->run(host, port, text);

    std::vector<std::thread> v;
    v.reserve(1);
    v.emplace_back(
        [&ioc]
        {
            ioc.run();
        });
    std::cout << "main\n";

    RequestMaker *request_maker_row = new RequestMaker(client_ptr);
    std::unique_ptr<IRequestMaker> request_maker_ptr(request_maker_row);

    ClientManager client_manager(std::move(request_maker_ptr));

    QApplication a(argc, argv); // запуск приложения
    GreetingPage w (nullptr, std::move(client_manager));
    w.show();
    return a.exec();
}
