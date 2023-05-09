#include "client_manager.hpp"

namespace json = boost::json;

void ClientManager::log_in(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request["request"] = "log in";
  request["context"].emplace_object() = json::value_from(user).as_object();
  //json::value jv(std::move(request));
  //std::cout << json::serialize(jv) << std::endl;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::log_out(unsigned id) {
  json::object request;
  request["request"] = "log out";
  request["context"].emplace_object()["id"] = id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::registration(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request["request"] = "email check";
  request["context"].emplace_object()["email"] = email;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  
  /*Somehow process response*/

  request.clear();
  request["request"] = "registration";
  request["context"].emplace_object() = json::value_from(user).as_object();
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::like(unsigned author_id, unsigned target_id) {
  json::object request;
  request["request"] = "like";
  request["context"].emplace_object()["author_id"] = author_id;
  request["context"].as_object()["target_id"] = target_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::dislike(unsigned author_id, unsigned target_id) {
  json::object request;
  request["request"] = "dislike";
  request["context"].emplace_object()["author_id"] = author_id;
  request["context"].as_object()["target_id"] = target_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::getNextProfile(unsigned author_id) {
  json::object request;
  request["request"] = "get next profile";
  request["context"].emplace_object()["author_id"] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}