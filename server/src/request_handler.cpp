#include "request_handler.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace json = boost::json;



RequestHandler::RequestHandler(std::shared_ptr<IDatabaseManager> dmp/*, std::unique_ptr<IRecommendation> rp*/)
  : database_manager_ptr_(dmp), /*recommendation_ptr_(std::move(rp)),*/ recommended_forms_() {}

http::response<http::string_body> RequestHandler::ReadRequest(std::string json) {
  json::error_code ec;
  json::value request = json::parse(json, ec);
  if (ec) return http::response<http::string_body>{http::status::bad_request, 11};

  std::string request_type = json::value_to<std::string>(request.as_object()[kRequestField]);

  // if (request_type == kEmailCheckRequest) {
  //   std::string email = json::value_to<std::string>(request.as_object()[kContextField].as_object()[kEmailField]);
  //   return EmailCheckResponse(database_manager_ptr_->CheckIfEmailBusy(email)); 
  // }

  if (request_type == kRegistrationRequest) {
    User user = json::value_to<User>(request.as_object()[kContextField]);
    unsigned new_id = database_manager_ptr_->addUser(user);

    return RegistrationResponse(new_id);
  }

  if (request_type == kLogInRequest) {
    User user = json::value_to<User>(request.as_object()[kContextField]);
    auto profile = database_manager_ptr_->authorise(user);
    return LogInResponse(profile);
  }

  if (request_type == kGetPossibleInterestRequest) {
    auto possibleInterests = database_manager_ptr_->getPossibleInterest();
    return GetPossibleInterestResponse(possibleInterests);
  }

  if (request_type == kGetPossibleLifestyleRequest ) {
    auto possibleLifestyles = database_manager_ptr_->getPossibleLifestyles();
    std::cout << "a" << std::endl;
    return GetPossibleLifestyleResponse(possibleLifestyles);
  }
  // if (request_type == kLogOutRequest) {
  //   unsigned id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kIdField]);
  //   /*some logic*/
  //   return LogOutResponse();
  // }
  
  if (request_type == kLikeRequest) {
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    unsigned target_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kTargetIdField]);
    bool is_like = json::value_to<bool>(request.as_object()[kContextField].as_object()["is_like"]);
    Match match(author_id, target_id, is_like);
    database_manager_ptr_->insertMatch(match);
    return LikeResponse();
  }

  if (request_type == kGetUserFormRequest) {
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    auto form = database_manager_ptr_->getUserForm(author_id);
    return GetUserFormResponce(form);
  }
  

  if (request_type == kGetNextProfileRequest) {
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    Form form = database_manager_ptr_->getUserForm(author_id);
    if (recommended_forms_.empty()) {
      Form author_form = database_manager_ptr_->getUserForm(author_id); 
      auto recommended_forms = database_manager_ptr_->getRecommendForms(form);
      Recommendation recommendation(author_form, recommended_forms);
      recommendation.recommend();
      SaveRecommendation(recommended_forms);
    }
    return GetNextProfileResponse();
  }

  // if (request_type == kEditFormRequest) {
  //   Profile/*Form*/ profile/*author_form*/ = json::value_to</*Form*/Profile>(request.as_object()[kContextField]/*.as_object()[kFormField]*/);
  //   /*bool IsTextChanged = json::value_to<bool>(request.as_object()[kContextField].as_object()[kIsTextChangedField])*/
  //   /*
  //   auto recommended_forms = database_manager_ptr_->getRecommendForms(form);
  //   if (IsTextChanged) {
  //     recommendation.vectorize_profile_text();
  //     database_manager_ptr_->editText(id, text);
  //   }
  //   */
  //   database_manager_ptr_->editForm(Form()/*author_form*/);
  //   return EditFormResponse();
  // }


  http::response<http::string_body> response{http::status::bad_request, 11};
  response.body() = "Unknown request.";
  return response;
}

http::response<http::string_body> RequestHandler::RegistrationResponse(unsigned new_id) {
  json::object response_body;
  response_body[kResponseField] = kRegistrationRequest;
  response_body[kContextField].emplace_object()[kIdField] = new_id;
  
  http::response<http::string_body> response{http::status::ok, 11};
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

http::response<http::string_body> RequestHandler::EmailCheckResponse(bool is_busy) {
  json::object response_body;
  response_body[kResponseField] = kEmailCheckRequest;
  response_body[kContextField].emplace_object()["is_busy"] = is_busy;
  
  http::response<http::string_body> response{http::status::ok, 11};
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

http::response<http::string_body> RequestHandler::LogInResponse(std::shared_ptr<Profile> profile) {
  json::object response_body;
  response_body[kResponseField] = kLogInRequest;
  if (profile.get()) {
    response_body[kContextField].emplace_object() = json::value_from(*profile.get()).as_object();
  } else {
    response_body[kContextField] = "Error: no such object!";
  }
  
  http::response<http::string_body> response{http::status::ok, 11};
  std::cout << response_body << std::endl;
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

// http::response<http::string_body> RequestHandler::LogOutResponse() {
//   json::object response_body;
//   response_body[kResponseField] = kLogOutRequest;
  
//   http::response<http::string_body> response{http::status::ok, 11};
//   response.body() = json::serialize(json::value(std::move(response_body)));
//   response.prepare_payload();
//   return response;
// }

http::response<http::string_body> RequestHandler::LikeResponse() {
  json::object response_body;
  response_body[kResponseField] = kLikeRequest;
  
  http::response<http::string_body> response{http::status::ok, 11};
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

// http::response<http::string_body> RequestHandler::DislikeResponse() {
//   json::object response_body;
//   response_body[kResponseField] = kDislikeRequest;
  
//   http::response<http::string_body> response{http::status::ok, 11};
//   response.body() = json::serialize(json::value(std::move(response_body)));
//   response.prepare_payload();
//   return response;
// }

http::response<http::string_body> RequestHandler::GetNextProfileResponse() {
  auto response = recommended_forms_.back();
  recommended_forms_.pop();
  return response;
}

http::response<http::string_body> RequestHandler::GetPossibleLifestyleResponse(std::vector<Lifestyle> possibleLifestyles) {
  json::object response_body;
  response_body[kResponseField] = kGetPossibleLifestyleRequest;
  json::array jarr;
  for (auto &possibleLifestyle: possibleLifestyles) {
    jarr.emplace_back(json::value_from(possibleLifestyle).as_object());
  }

  response_body["possible lifestyles"].emplace_array() = jarr;
  http::response<http::string_body> response{http::status::ok, 11};
  std::cout << response_body << std::endl;
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

http::response<http::string_body> RequestHandler::GetPossibleInterestResponse(std::vector<Interest> possibleInterests) {
  json::object response_body;
  response_body[kResponseField] = kGetPossibleInterestRequest;
  json::array jarr;
  for (auto &possibleInterest: possibleInterests) {
    jarr.emplace_back(json::value_from(possibleInterest).as_object());
  }
  response_body["possible interests"].emplace_array() = jarr;
  http::response<http::string_body> response{http::status::ok, 11};
  std::cout << response_body << std::endl;
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

http::response<http::string_body> RequestHandler::GetUserFormResponce(Form form) {
  json::object response_body;
  response_body[kResponseField] = kGetUserFormRequest;
  response_body[kContextField].emplace_object() = json::value_from(form).as_object();
  
  http::response<http::string_body> response{http::status::ok, 11};
  std::cout << response_body << std::endl;
  response.body() = json::serialize(json::value(std::move(response_body)));
  response.prepare_payload();
  return response;
}

void RequestHandler::SaveRecommendation(std::vector<Form> &recommended_forms)
{
  for (auto form: recommended_forms) {
    json::object response_body;
    response_body[kResponseField] = kGetNextProfileRequest;
    //response_body[kcontextField].emplace_object() = json::value_from(form).as_object();
    http::response<http::string_body> response{http::status::ok, 11};
    response.body() = json::serialize(json::value(std::move(response_body)));
    response.prepare_payload();
    recommended_forms_.push(response);
  }
}

// http::response<http::string_body> RequestHandler::EditFormResponse() {
//   json::object response_body;
//   response_body[kResponseField] = kEditFormRequest;
  
//   http::response<http::string_body> response{http::status::ok, 11};
//   response.body() = json::serialize(json::value(std::move(response_body)));
//   response.prepare_payload();
//   return response;
// }


// void RequestHandler::JsonParser(std::string json) {

// }

// void RequestHandler::CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) {}
