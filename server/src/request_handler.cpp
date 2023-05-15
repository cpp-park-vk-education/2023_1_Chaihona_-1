#include "request_handler.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace json = boost::json;



RequestHandler::RequestHandler(std::shared_ptr<IDatabaseManager> dmp/*, std::unique_ptr<IRecommendation> rp*/)
  : database_manager_ptr_(dmp), /*recommendation_ptr_(std::move(rp)),*/ recommended_forms_() {}

std::string RequestHandler::ReadRequest(std::string json) {
  json::error_code ec;
  json::value request = json::parse(json, ec);
  if (ec) {
    json::object response_body;
    response_body[kResponseField] = "bad request";
    return json::serialize(json::value(std::move(response_body)));
  }

  std::string request_type = json::value_to<std::string>(request.as_object()[kRequestField]);

  if (request_type == kEmailCheckRequest) {
    std::string email = json::value_to<std::string>(request.as_object()[kContextField].as_object()[kEmailField]);
    return EmailCheckResponse(database_manager_ptr_->checkIfEmailBusy(email)); 
  }

  if (request_type == kLoginCheckRequest) {
    std::string login = json::value_to<std::string>(request.as_object()[kContextField].as_object()[kEmailField]);
    //return LoginCheckResponse(database_manager_ptr_->checkIfLoginBusy(login)); 
  }

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
  
  // if (request_type == kGetPossibleInterestRequest) {
  //   auto possibleInterests = database_manager_ptr_->getPossibleInterest();
  //   return GetPossibleInterestResponse(possibleInterests);
  // }

  // if (request_type == kGetPossibleLifestyleRequest) {
  //   auto possibleLifestyles = database_manager_ptr_->getPossibleLifestyles();
  //   std::cout << "a" << std::endl;
  //   return GetPossibleLifestyleResponse(possibleLifestyles);
  // }

  if (request_type == kLikeRequest) {
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    unsigned target_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kTargetIdField]);
    bool is_like = json::value_to<bool>(request.as_object()[kContextField].as_object()[kIsLikeField]);
    // Match match(author_id, target_id, is_like);
    // database_manager_ptr_->insertMatch(match);
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

  if (request_type == kEditFormRequest) {
    Profile/*Form*/ profile/*author_form*/ = json::value_to</*Form*/Profile>(request.as_object()[kContextField]/*.as_object()[kFormField]*/);
    /*bool IsTextChanged = json::value_to<bool>(request.as_object()[kContextField].as_object()[kIsTextChangedField])*/
    /*
    auto recommended_forms = database_manager_ptr_->getRecommendForms(form);
    if (IsTextChanged) {
      Recommendation recommendation(author_form, recommended_forms);
      recommendation.vectorize_profile_text();
      database_manager_ptr_->editText(id, text);
    }
    */
    //database_manager_ptr_->editForm(Form()/*author_form*/);
    return EditFormResponse();
  }

  if (request_type == kAddFormReqeust) {
    Form form = json::value_to<Form>(request.as_object()[kContextField].as_object()[kFormField]);
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    // Recommendation recommendation(form, std::vector<Form>());
    // recommendation.vectorize_profile_text();
    // database_manager_ptr_->addForm(author_id, form);
    return AddFormResponse();
  }

  if (request_type == kGetMatchTable) {
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    //std::vector<Form> forms = database_manager_ptr_->getMatchTable(author_id);
    //return GetMatchTableResponse(forms);
  }

  if (request_type == kAddInterestRequest) {
    UserInterest interest = json::value_to<UserInterest>(request.as_object()[kContextField].as_object()[kInterestField]);
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    //database_manager_ptr_->addInterest(author_id, interest);
    return AddInterestResponse();
  }

  if (request_type == kAddLifestyleRequest) {
    UserLifestyle lifestyle = json::value_to<UserLifestyle>(request.as_object()[kContextField].as_object()[kLifestyleField]);
    unsigned author_id = json::value_to<unsigned>(request.as_object()[kContextField].as_object()[kAuthorIdField]);
    //database_manager_ptr_->addLifestyle(author_id, lifestyle);
    return AddLifestyleResponse();
  }

  // http::response<http::string_body> response{http::status::bad_request, 11};
  // response.body() = "unknown request";
  json::object response_body;
  response_body[kResponseField] = "unknown request";
  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::RegistrationResponse(unsigned new_id) {
  json::object response_body;
  response_body[kResponseField] = kRegistrationRequest;
  response_body[kContextField].emplace_object()[kIdField] = new_id;
  
  //http::response<http::string_body> response{http::status::ok, 11};
  std::string response = json::serialize(json::value(std::move(response_body)));
  //response.prepare_payload();
  return response;
}

std::string RequestHandler::EmailCheckResponse(bool is_busy) {
  json::object response_body;
  response_body[kResponseField] = kEmailCheckRequest;
  response_body[kContextField].emplace_object()[kIsBusyField] = is_busy;
  
  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::LoginCheckResponse(bool is_busy) {
  json::object response_body;
  response_body[kResponseField] = kLoginCheckRequest;
  response_body[kContextField].emplace_object()[kIsBusyField] = is_busy;
  
  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::LogInResponse(std::shared_ptr<Profile> profile) {
  json::object response_body;
  response_body[kResponseField] = kLogInRequest;
  if (profile.get()) {
    response_body[kContextField].emplace_object() = json::value_from(*profile.get()).as_object();
  } else {
    response_body[kContextField] = kErrorNoSuchObject;
  }

  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::LikeResponse() {
  json::object response_body;
  response_body[kResponseField] = kLikeRequest;

  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::GetNextProfileResponse() {
  auto response = recommended_forms_.back();
  recommended_forms_.pop();
  return response;
}

std::string RequestHandler::GetPossibleLifestyleResponse(std::vector<Lifestyle> possibleLifestyles) {
  json::object response_body;
  response_body[kResponseField] = kGetPossibleLifestyleRequest;
  json::array jarr;
  for (auto &possibleLifestyle: possibleLifestyles) {
    jarr.emplace_back(json::value_from(possibleLifestyle).as_object());
  }

  response_body[kContextField].emplace_array() = jarr;
  std::string response = json::serialize(json::value(std::move(response_body)));
  return response;
}

std::string RequestHandler::GetPossibleInterestResponse(std::vector<Interest> possibleInterests) {
  json::object response_body;
  response_body[kResponseField] = kGetPossibleInterestRequest;
  json::array jarr;
  for (auto &possibleInterest: possibleInterests) {
    jarr.emplace_back(json::value_from(possibleInterest).as_object());
  }
  response_body[kContextField].emplace_array() = jarr;
  std::string response = json::serialize(json::value(std::move(response_body)));
  return response;
}

std::string RequestHandler::GetUserFormResponce(Form form) {
  json::object response_body;
  response_body[kResponseField] = kGetUserFormRequest;
  response_body[kContextField].emplace_object() = json::value_from(form).as_object();
  
  std::string response = json::serialize(json::value(std::move(response_body)));
  return response;
}

void RequestHandler::SaveRecommendation (std::vector<Form>& recommended_forms) {
  for (auto form: recommended_forms) {
    json::object response_body;
    response_body[kResponseField] = kGetNextProfileRequest;
    //response_body[kcontextField].emplace_object() = json::value_from(form).as_object();
    std::string response = json::serialize(json::value(std::move(response_body)));
    recommended_forms_.push(response);
  }
}

std::string RequestHandler::EditFormResponse() {
  json::object response_body;
  response_body[kResponseField] = kEditFormRequest;
  
  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::AddFormResponse() {
  json::object response_body;
  response_body[kResponseField] = kAddFormReqeust;

  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::AddInterestResponse() {
  json::object response_body;
  response_body[kResponseField] = kAddInterestRequest;
  
  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::AddLifestyleResponse() {
  json::object response_body;
  response_body[kResponseField] = kAddLifestyleRequest;

  return json::serialize(json::value(std::move(response_body)));
}

std::string RequestHandler::GetMatchTableResponse(std::vector<Form> forms) {
  json::object response_body;
  response_body[kResponseField] = kGetMatchTable;
  response_body[kContextField].emplace_object() = json::value_from(forms).as_object();
  
  std::string response = json::serialize(json::value(std::move(response_body)));
  return response;
}