#pragma once

#include <memory>
#include <string>
#include "client.hpp"

class IRequestMaker {
public:
  virtual void MakeRequest(std::string json_path) = 0;
};

class RequestMaker: public IRequestMaker {
public:
  RequestMaker(std::unique_ptr<IClient> client);
  virtual void MakeRequest(std::string json_path) override;
};