#include "request_maker.hpp"
#include <iostream>
#include <chrono>
#include <thread>


RequestMaker::RequestMaker(std::shared_ptr<IClient> cp): client_ptr_(cp) {}

void RequestMaker::MakeRequest(std::string json) {
  //std::cout << json << std::endl;
  client_ptr_->set_request(json);
}

std::string RequestMaker::getResponse(std::string request_type) {
  for (int i = 0; i < 10; std::this_thread::sleep_for(std::chrono::seconds(1)), ++i) {
    std::queue<std::string> responses = client_ptr_->getResponses();
    if (!responses.empty()) {
      std::string response = responses.back();
      if (response.find(request_type) != -1){
        responses.pop();
        return response;
      }
    }
  }
  std::cout << kNoResponse << std::endl;
  return std::string(kNoResponse);
}

void RequestMaker::Close() {
  std::cout << "close" << std::endl;
  client_ptr_->close();
}