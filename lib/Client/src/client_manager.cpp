#include "client_manager.hpp"

namespace json = boost::json;

void ClientManager::log_in(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request[kRequestField] = kLogInRequest;
  request[kContextField].emplace_object() = json::value_from(user).as_object();
  //json::value jv(std::move(request));
  //std::cout << json::serialize(jv) << std::endl;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::log_out(unsigned id) {
  json::object request;
  request[kRequestField] = kLogOutRequest;
  request[kContextField].emplace_object()[kIdField] = id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::registration(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request[kRequestField] = kEmailCheckRequest;
  request[kContextField].emplace_object()[kEmailField] = email;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request)))); //GET request
  
  /*Somehow process response*/

  request.clear();
  request[kRequestField] = kRegistrationRequest;
  request[kContextField].emplace_object() = json::value_from(user).as_object();
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::like(unsigned author_id, unsigned target_id) {
  json::object request;
  request[kRequestField] = kLikeRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request[kContextField].as_object()[kTargetIdField] = target_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::dislike(unsigned author_id, unsigned target_id) {
  json::object request;
  request[kRequestField] = kDislikeRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request[kContextField].as_object()[kTargetIdField] = target_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::getNextProfile(unsigned author_id) {
  json::object request;
  request[kRequestField] = kGetNextProfileRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
}

void ClientManager::close() {
  request_maker_ptr_->Close();
}