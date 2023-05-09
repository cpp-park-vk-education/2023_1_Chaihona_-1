#include "request_maker.hpp"
#include <iostream>

RequestMaker::RequestMaker(std::unique_ptr<IClient> cp): client_ptr_(std::move(cp)) {}

void RequestMaker::MakeRequest(std::string json) {
  std::cout << json << std::endl;
  client_ptr_->set_request(json);
}