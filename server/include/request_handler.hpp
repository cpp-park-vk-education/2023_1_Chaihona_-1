#pragma once

#include <iostream>
#include <memory>
#include <boost/beast.hpp>
#include <boost/json.hpp>
#include <queue>
#include "DBManager.hpp"
#include "user.hpp"
#include "match.hpp"
#include "lifestyle.hpp"
#include "interest.hpp"
#include "recommendation.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


inline constexpr std::string_view kRegistrationRequest = "registration";
inline constexpr std::string_view kLogInRequest = "log in";
inline constexpr std::string_view kLogOutRequest = "log out";
inline constexpr std::string_view kEmailCheckRequest = "email check";
inline constexpr std::string_view kLikeRequest = "like";
inline constexpr std::string_view kDislikeRequest = "dislike";
inline constexpr std::string_view kGetNextProfileRequest = "get next profile";
inline constexpr std::string_view kGetPossibleInterestRequest = "get possible interest";
inline constexpr std::string_view kGetPossibleLifestyleRequest = "get possible lifestyle";
inline constexpr std::string_view kGetUserFormRequest = "get user form";
inline constexpr std::string_view kEditFormRequest = "edit form";
inline constexpr std::string_view kContextField = "context";
inline constexpr std::string_view kRequestField = "request";
inline constexpr std::string_view kIdField = "id";
inline constexpr std::string_view kAuthorIdField = "author_id";
inline constexpr std::string_view kTargetIdField = "target_id";
inline constexpr std::string_view kEmailField = "email";
inline constexpr std::string_view kResponseField = "response";


class IRequestHandler {
public:
  virtual http::response<http::string_body> ReadRequest(std::string json) = 0;

private:
  virtual http::response<http::string_body> RegistrationResponse(unsigned new_id) = 0;
  virtual http::response<http::string_body> EmailCheckResponse(bool) = 0;
  virtual http::response<http::string_body> LogInResponse(std::shared_ptr<Profile>) = 0;
  // virtual http::response<http::string_body> LogOutResponse() = 0;
  virtual http::response<http::string_body> LikeResponse() = 0;
  // virtual http::response<http::string_body> DislikeResponse() = 0;
  // virtual http::response<http::string_body> EditFormResponse() = 0;
  virtual http::response<http::string_body> GetNextProfileResponse() = 0;
  virtual http::response<http::string_body> GetPossibleLifestyleResponse(std::vector<Lifestyle>) = 0;
  virtual http::response<http::string_body> GetPossibleInterestResponse(std::vector<Interest>) = 0;
  virtual http::response<http::string_body> GetUserFormResponce(Form) = 0;
  //virtual void JsonParser(std::string json) = 0;
  //virtual void CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) = 0;
};

class RequestHandler : public IRequestHandler {
public:
  RequestHandler(std::shared_ptr<IDatabaseManager> dmp/*, std::unique_ptr<IRecommendation> rp*/);
  virtual http::response<http::string_body> ReadRequest(std::string json) override;

private:
  std::shared_ptr<IDatabaseManager> database_manager_ptr_;
  //std::shared_ptr<IRecommendation> recommendation_ptr_;
  std::queue<http::response<http::string_body>> recommended_forms_;

  virtual http::response<http::string_body> RegistrationResponse(unsigned new_id) override;
  virtual http::response<http::string_body> EmailCheckResponse(bool) override;
  virtual http::response<http::string_body> LogInResponse(std::shared_ptr<Profile>) override;
  // virtual http::response<http::string_body> LogOutResponse() override;
  virtual http::response<http::string_body> LikeResponse() override;
  // virtual http::response<http::string_body> DislikeResponse() override;
  // virtual http::response<http::string_body> EditFormResponse() override;
  virtual http::response<http::string_body> GetNextProfileResponse() override;
  virtual http::response<http::string_body> GetPossibleLifestyleResponse(std::vector<Lifestyle>) override;
  virtual http::response<http::string_body> GetPossibleInterestResponse(std::vector<Interest>) override;
  virtual http::response<http::string_body> GetUserFormResponce(Form) override;
  void SaveRecommendation(std::vector<Form>& recommended_forms);
  
  // virtual void JsonParser(std::string json) override;
  //virtual void CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) override;
  /*Request Parametres*/
};
