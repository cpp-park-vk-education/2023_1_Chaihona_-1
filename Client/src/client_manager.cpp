#include "client_manager.hpp"

namespace json = boost::json;

Profile ClientManager::log_in(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request[kRequestField] = kLogInRequest;
  request[kContextField].emplace_object() = json::value_from(user).as_object();
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kLogInRequest));
  return log_in_response(response);
}

Profile ClientManager::log_in_response(std::string json) { 
  if (json == kNoResponse) return Profile();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return Profile();

  return json::value_to<Profile>(response.as_object()[kContextField]);
}

bool ClientManager::email_check(std::string email) { 
  json::object request;
  request[kRequestField] = kEmailCheckRequest;
  request[kContextField].emplace_object()[kEmailField] = email;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request)))); //GET request
  std::string response = request_maker_ptr_->getResponse(std::string(kEmailCheckRequest));
  return email_check_response(response);
}

bool ClientManager::email_check_response(std::string json) {
  if (json == kNoResponse) return false;
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return false;
  return json::value_to<bool>(response.as_object()[kContextField].as_object()[kIsBusyField]);
}

unsigned ClientManager::registration(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request.clear();
  request[kRequestField] = kRegistrationRequest;
  request[kContextField].emplace_object() = json::value_from(user).as_object();
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kRegistrationRequest));
  return registration_response(response);
}

unsigned ClientManager::registration_response(std::string json) {
  if (json == kNoResponse) return 0;
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return 0;
  return json::value_to<unsigned>(response.as_object()[kContextField].as_object()[kIdField]);
}

void ClientManager::react(unsigned author_id, unsigned target_id/*, MATCHTYPES reaction*/) {
  json::object request;
  request[kRequestField] = kLikeRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request[kContextField].as_object()[kTargetIdField] = target_id;
  //request[kContextField].as_object()[kReactionField] = reaction;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  request_maker_ptr_->getResponse(std::string(kLikeRequest));
}

Form ClientManager::getNextProfile(unsigned author_id) {
  json::object request;
  request[kRequestField] = kGetNextProfileRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kGetNextProfileRequest));
  return getNextProfile_response(response);
}

Form ClientManager::getNextProfile_response(std::string json) {
  if (json == kNoResponse) return Form();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return Form();

  return json::value_to<Form>(response.as_object()[kContextField]);
}


void ClientManager::close() {
  request_maker_ptr_->Close();
}