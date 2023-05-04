#pragma once
#include <boost/beast.hpp>

class IClient { 
public:
  virtual ~IClient() {} 
  virtual void run() = 0;
  virtual void set_request(std::string json_path) = 0;
private:
  virtual void on_resolve() = 0;
  virtual void on_connect() = 0;
  virtual void on_write() = 0;
  virtual void on_read() = 0;
};

class Client : public IClient { 
public:
  virtual void run() override;
  virtual void set_request(std::string json_path) = 0;
private:
  virtual void on_resolve() override;
  virtual void on_connect()override;
  virtual void on_write() override;
  virtual void on_read() override;
};

