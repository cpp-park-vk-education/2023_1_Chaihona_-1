#pragma once

#include <iostream>
#include <memory>
#include <boost/beast.hpp>
#include <boost/json.hpp>
#include <queue>
#include "DBManager.hpp"
#include "user.hpp"
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
inline constexpr std::string_view kEditFormRequest = "edit form";
inline constexpr std::string_view kContextField = "context";
inline constexpr std::string_view kRequestField = "request";
inline constexpr std::string_view kIdField = "id";
inline constexpr std::string_view kAuthorIdField = "author_id";
inline constexpr std::string_view kTargetIdField = "target_id";
inline constexpr std::string_view kEmailField = "email";
inline constexpr std::string_view kResponseField = "response";
inline constexpr std::string_view kIsBusyField = "is_busy";
inline constexpr std::string_view kReactionField = "reaction";

class IRequestHandler {
public:
  virtual std::string ReadRequest(std::string json) = 0;

private:
  virtual std::string RegistrationResponse(unsigned new_id) = 0;
  virtual std::string EmailCheckResponse(bool) = 0;
  virtual std::string LogInResponse(Profile) = 0;
  virtual std::string LikeResponse() = 0;
  virtual std::string EditFormResponse() = 0;
  virtual std::string GetNextProfileResponse() = 0;

  //virtual void JsonParser(std::string json) = 0;
  //virtual void CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) = 0;
};

class RequestHandler : public IRequestHandler {
public:
  RequestHandler(std::shared_ptr<IDatabaseManager> dmp/*, std::unique_ptr<IRecommendation> rp*/);
  virtual std::string ReadRequest(std::string json) override;

private:
  std::shared_ptr<IDatabaseManager> database_manager_ptr_;
  //std::shared_ptr<IRecommendation> recommendation_ptr_;
  std::queue<std::string> recommended_forms_;

  virtual std::string RegistrationResponse(unsigned new_id) override;
  virtual std::string EmailCheckResponse(bool) override;
  virtual std::string LogInResponse(Profile) override;
  virtual std::string LikeResponse() override;
  virtual std::string EditFormResponse() override;
  virtual std::string GetNextProfileResponse() override;
  void SaveRecommendation(std::vector<Form>& recommended_forms);
};
