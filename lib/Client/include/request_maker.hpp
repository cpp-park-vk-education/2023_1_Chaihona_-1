#pragma once

#include <memory>
#include <string>
#include "client.hpp"

class IRequestMaker {
public:
  virtual void MakeRequest(std::string json) = 0;
  virtual void Close() = 0;
};

class RequestMaker: public IRequestMaker {
public:

  RequestMaker(std::shared_ptr<IClient> cp);
  virtual void MakeRequest(std::string json) override;
  virtual void Close() override;

private:

  std::shared_ptr<IClient> client_ptr_;

};