#pragma once
#include <iostream>
#include <memory>
#include <boost/json.hpp>
#include "request_maker.hpp"
#include <chrono>
#include <thread>
#include "user.hpp"

namespace json = boost::json;

class ClientManager
{
public:
  ~ClientManager() {}
  ClientManager(std::unique_ptr<IRequestMaker> rmp) : request_maker_ptr_(std::move(rmp)) {}
  
  bool email_check(std::string email);
  Profile log_in(std::string email, std::string password);
  unsigned registration(std::string email, std::string password);
  void react(unsigned author_id, unsigned target_id);
  Form getNextProfile(unsigned author_id);
  void close();
  ClientManager(ClientManager &&client_manager) : request_maker_ptr_(std::move(client_manager.request_maker_ptr_)) {}

private:
  bool email_check_response(std::string json);
  unsigned registration_response(std::string json);
  Profile log_in_response(std::string json);
  Form getNextProfile_response(std::string json);

  std::unique_ptr<IRequestMaker> request_maker_ptr_;
};
