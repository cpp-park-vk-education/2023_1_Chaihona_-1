#pragma once

#include <memory>
#include <string>
#include "client.hpp"

class IRequestMaker {
public:
  virtual void MakeRequest(std::string json) = 0;
};

class RequestMaker: public IRequestMaker {
public:

  RequestMaker(std::unique_ptr<IClient> cp);
  virtual void MakeRequest(std::string json) override;

private:

  std::unique_ptr<IClient> client_ptr_;

};