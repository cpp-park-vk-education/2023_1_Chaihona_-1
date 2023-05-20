#include "client_manager.hpp"

namespace json = boost::json;

Profile* ClientManager::log_in(std::string email, std::string password) {
  User user{email, password};
  json::object request;
  request[kRequestField] = kLogInRequest;
  request[kContextField].emplace_object() = json::value_from(user).as_object();
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kLogInRequest));
  return log_in_response(response);
}

Profile* ClientManager::log_in_response(std::string json) { 
  if (json == kNoResponse) return nullptr;
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (response.as_object()[kContextField] == "Error: no such object!") {
    std::cerr << "no profile!" << std::endl;
    return nullptr;
  } 

  Profile profile = json::value_to<Profile>(response.as_object()[kContextField]);
  profile_ = profile;
  return  &profile_;
}

std::vector<Interest> ClientManager::GetPossibleInterest() {
  json::object request;
  request[kRequestField] = kGetPossibleInterestRequest;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kGetPossibleInterestRequest));
  return get_possible_interest_response(response);
}

std::vector<Interest> ClientManager::get_possible_interest_response(std::string json) { 
  if (json == kNoResponse) return std::vector<Interest>();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return std::vector<Interest>();

  return json::value_to<std::vector<Interest>>(response.as_object()[kContextField]); //??
}

std::vector<Lifestyle> ClientManager::GetPossibleLifestyle() {
  json::object request;
  request[kRequestField] = kGetPossibleLifestyleRequest;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kGetPossibleLifestyleRequest));
  return get_possible_lifestyle_response(response);
}

std::vector<Lifestyle> ClientManager::get_possible_lifestyle_response(std::string json) {
  if (json == kNoResponse) return std::vector<Lifestyle>();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return std::vector<Lifestyle>();

  return json::value_to<std::vector<Lifestyle>>(response.as_object()[kContextField]); //??
}

Form ClientManager::GetUserForm(unsigned author_id) {
  json::object request;
  request[kRequestField] = kGetUserFormRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kGetUserFormRequest));
  return get_user_form_response(response);
}

Form ClientManager::get_user_form_response(std::string json) {
  if (json == kNoResponse) return Form();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return Form();

  Form form = json::value_to<Form>(response.as_object()[kContextField]);
  form_ = form;
  return form;
}

bool ClientManager::email_check(std::string email) { 
  json::object request;
  request[kRequestField] = kEmailCheckRequest;
  request[kContextField].emplace_object()[kEmailField] = email;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
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

bool ClientManager::login_check(std::string login) {
  json::object request;
  request[kRequestField] = kLoginCheckRequest;
  request[kContextField].emplace_object()[kEmailField] = login;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request)))); 
  std::string response = request_maker_ptr_->getResponse(std::string(kLoginCheckRequest));
  return email_check_response(response);
}

bool ClientManager::login_check_response(std::string json) {
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

void ClientManager::react(unsigned author_id, unsigned target_id, bool is_like) {
  json::object request;
  request[kRequestField] = kLikeRequest;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request[kContextField].as_object()[kTargetIdField] = target_id;
  request[kContextField].as_object()[kIsLikeField] = is_like;
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

void ClientManager::EditForm(Form form, bool is_text_changed) {
  json::object request;
  request[kRequestField] = kEditFormRequest;
  request[kContextField].emplace_object()[kFormField] = json::value_from(form).as_object();
  request[kContextField].as_object()[kIsTextChangedField] = is_text_changed;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  request_maker_ptr_->getResponse(std::string(kEditFormRequest));
}

void ClientManager::AddForm(unsigned author_id, Form form) {
  json::object request;
  request[kRequestField] = kAddFormReqeust;
  request[kContextField].emplace_object()[kFormField] = json::value_from(form).as_object();
  request[kContextField].as_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  request_maker_ptr_->getResponse(std::string(kAddFormReqeust)); 
}

std::vector<Form> ClientManager::GetMatchTable(unsigned author_id) {
  json::object request;
  request[kRequestField] = kGetMatchTable;
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  std::string response = request_maker_ptr_->getResponse(std::string(kGetMatchTable)); 
  return get_match_table_response(response);
}

std::vector<Form> ClientManager::get_match_table_response(std::string json) {
  if (json == kNoResponse) return std::vector<Form>();
  json::error_code ec;
  json::value response = json::parse(json, ec);
  if (ec) return std::vector<Form>();

  return json::value_to<std::vector<Form>>(response.as_object()[kContextField]);
}

void ClientManager::AddInterest(unsigned author_id, UserInterest interest) {
  json::object request;
  request[kRequestField] = kAddInterestRequest;
  request[kContextField].emplace_object()[kInterestField] = json::value_from(interest).as_object();
  request[kContextField].emplace_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  request_maker_ptr_->getResponse(std::string(kAddInterestRequest));
}

void ClientManager::AddLifestyle(unsigned author_id, UserLifestyle lifestyle) {
  json::object request;
  request[kRequestField] = kAddLifestyleRequest;
  request[kContextField].emplace_object()[kLifestyleField] = json::value_from(lifestyle).as_object();
  request[kContextField].as_object()[kAuthorIdField] = author_id;
  request_maker_ptr_->MakeRequest(json::serialize(json::value(std::move(request))));
  request_maker_ptr_->getResponse(std::string(kAddLifestyleRequest));
}

void ClientManager::close() {
  request_maker_ptr_->Close();
}