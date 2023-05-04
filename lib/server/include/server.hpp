#pragma once

#include <string>
#include <gmock/gmock.h>

class IServer/*: public std::enable_shared_from_this<IServer>*/ {
public:
  virtual ~IServer() {}
  virtual void run() = 0;
private:
  virtual void do_accept() = 0;
  virtual void on_accept() = 0;

};

class Server : public IServer {
public:
  virtual void run() override; 
private:
  virtual void do_accept() override;
  virtual void on_accept() override;
};