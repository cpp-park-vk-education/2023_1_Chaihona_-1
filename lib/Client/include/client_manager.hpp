#pragma once
#include <string>
#include <memory>
#include "request_maker.hpp"

class IClientManager { 
public:
  virtual ~IClientManager() {} 
  virtual void log_in(std::string email, std::string password) = 0;
  virtual void log_out(unsigned id) = 0;
  virtual void registration(std::string email, std::string password) = 0;
  virtual void like(unsigned author_id, unsigned target_id) = 0;
  virtual void dislike(unsigned author_id, unsigned target_id) = 0;
  virtual void getNextProfile(unsigned author_id) = 0;
};

class ClientManager : public IClientManager { 
public:
  ClientManager(std::unique_ptr<IRequestMaker>);
  virtual void log_in(std::string email, std::string password) override;
  virtual void log_out(unsigned id) override;
  virtual void registration(std::string email, std::string password) override;
  virtual void like(unsigned author_id, unsigned target_id) override;
  virtual void dislike(unsigned author_id, unsigned target_id) override;
  virtual void getNextProfile(unsigned author_id) override;
};

