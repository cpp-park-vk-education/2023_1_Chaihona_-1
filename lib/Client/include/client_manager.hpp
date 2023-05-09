#pragma once
#include <iostream>
#include <memory>
#include <boost/json.hpp>
#include "request_maker.hpp"
#include "user.hpp"

namespace json = boost::json;



class IClientManager { 
public:
  virtual ~IClientManager() {} 
  virtual void log_in(std::string email, std::string password) = 0;
  virtual void log_out(unsigned id) = 0;
  virtual void registration(std::string email, std::string password) = 0;
  virtual void like(unsigned author_id, unsigned target_id) = 0;
  virtual void dislike(unsigned author_id, unsigned target_id) = 0;
  virtual void getNextProfile(unsigned author_id) = 0;
  virtual void close() = 0;
};

class ClientManager : public IClientManager { 
public:
  virtual ~ClientManager() {} 
  ClientManager(std::unique_ptr<IRequestMaker> rmp) : request_maker_ptr_(std::move(rmp)) {}
  
  virtual void log_in(std::string email, std::string password) override;
  virtual void log_out(unsigned id) override;
  virtual void registration(std::string email, std::string password) override;
  virtual void like(unsigned author_id, unsigned target_id) override;
  virtual void dislike(unsigned author_id, unsigned target_id) override;
  virtual void getNextProfile(unsigned author_id) override;
  virtual void close() override;

private:

  std::unique_ptr<IRequestMaker> request_maker_ptr_;
};

