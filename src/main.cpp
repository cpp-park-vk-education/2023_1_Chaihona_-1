#include <iostream>
#include "client_manager.hpp"
#include <boost/json/src.hpp>
#include <thread>
#include <vector>


int main(int argc, char** argv) {
  auto const host = "127.0.0.1";
  auto const port = "1240";
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

  client_ptr->set_request("kek");
  std::string operation;
  while (std::cin >> operation){
    if (operation == "close"){
      client_ptr->close();
    }
    client_ptr->set_request(operation);
  }
  // Run the I/O service. The call will return when
  // the socket is closed.
  //ioc.run();

  return EXIT_SUCCESS;

  // std::unique_ptr<IClient> client_ptr(new Client());

  // std::unique_ptr<IRequestMaker> request_maker_ptr(new RequestMaker(std::move(client_ptr)));

  
  // ClientManager client_manager(std::move(request_maker_ptr));
  // client_manager.like(54321, 12345);
}