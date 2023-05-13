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

  void log_in(std::string email, std::string password);
  void log_out(unsigned id);
  void registration(std::string email, std::string password);
  void like(unsigned author_id, unsigned target_id);
  void dislike(unsigned author_id, unsigned target_id);
  void getNextProfile(unsigned author_id);
  void close();
  ClientManager(ClientManager &&client_manager) : request_maker_ptr_(std::move(client_manager.request_maker_ptr_)) {}

private:
  std::unique_ptr<IRequestMaker> request_maker_ptr_;
};
