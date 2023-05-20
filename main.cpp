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
#include "user.hpp"


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


    // Interest interest(1, "a", "a");
    // Lifestyle lifestyle (1, "a", "a", std::vector<std::string>());
    // UserInterest ui (0, interest,10,0);
    // UserLifestyle ulf(0, lifestyle, "aquarius");
    // std::vector<UserInterest> uivec; uivec.push_back(ui);
    // std::vector<UserLifestyle> ulfvec; ulfvec.push_back(ulf);
    // Preference pref(18,40,10,'M');
    // Form form(0, uivec, ulfvec, "a", "b", "c", "d",0, 'M', "2002-02-02", pref);
    // //client_manager.AddForm(1, form);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // //client_manager.react(1, 18, true);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // client_manager.GetMatchTable(1);

    QApplication a(argc, argv); // запуск приложения
    GreetingPage w (nullptr, std::move(client_manager));
    w.show();
    return a.exec();
}
