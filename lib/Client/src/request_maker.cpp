#include "request_maker.hpp"
#include <iostream>

RequestMaker::RequestMaker(std::shared_ptr<IClient> cp): client_ptr_(cp) {}

void RequestMaker::MakeRequest(std::string json) {
  //std::cout << json << std::endl;
  client_ptr_->set_request(json);
}

void RequestMaker::Close() {
  std::cout << "close" << std::endl;
  client_ptr_->close();
}