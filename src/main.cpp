#include <iostream>
#include "client_manager.hpp"
#include <boost/json/src.hpp>
#include <thread>
#include <chrono>
#include <vector>


int main(int argc, char** argv) {
  auto const host = "127.0.0.1";
  auto const port = "1237";
  //auto const host = "8.8.8.8";
  //auto const port = "80";
  auto const text = "lol";

  // The io_context is required for all I/O
  net::io_context ioc;

  // Launch the asynchronous operation
  auto client_ptr = std::make_shared<Client>(ioc);
  client_ptr->run(host, port, text);
  
  std::vector<std::thread> v;
  v.reserve(1);
  v.emplace_back(
    [&ioc]{
      ioc.run();
    }
  );
  std::cout << "main\n";

  // client_ptr->set_request("kek");
  // std::string operation;
  // while (std::cin >> operation){
  //   if (operation == "close"){
  //     client_ptr->close();
  //   }
  //   client_ptr->set_request(operation);
  // }


  // client_ptr->close();
  // std::this_thread::sleep_for(std::chrono::milliseconds(100));
  // Run the I/O service. The call will return when
  // the socket is closed.
  //ioc.run();
  RequestMaker* request_maker_row = new RequestMaker(client_ptr);
  std::unique_ptr<IRequestMaker> request_maker_ptr(request_maker_row);


  ClientManager client_manager(std::move(request_maker_ptr));
  client_manager.registration("lol@yandex.ru", "12345");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.log_in("lol@yandex.ru", "12345");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.dislike(54321, 12345);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.getNextProfile(12345);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.like(54321, 12345);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.log_out(12345);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  client_manager.close();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return EXIT_SUCCESS;
}