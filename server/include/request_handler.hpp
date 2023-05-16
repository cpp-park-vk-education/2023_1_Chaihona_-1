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
inline constexpr std::string_view kLoginCheckRequest = "login check";
inline constexpr std::string_view kLikeRequest = "like";
inline constexpr std::string_view kDislikeRequest = "dislike";
inline constexpr std::string_view kGetNextProfileRequest = "get next profile";
inline constexpr std::string_view kGetPossibleInterestRequest = "get possible interest";
inline constexpr std::string_view kGetPossibleLifestyleRequest = "get possible lifestyle";
inline constexpr std::string_view kAddFormReqeust = "add form";
inline constexpr std::string_view kGetUserFormRequest = "get user form";
inline constexpr std::string_view kEditFormRequest = "edit form";
inline constexpr std::string_view kAddInterestRequest = "add interest";
inline constexpr std::string_view kAddLifestyleRequest = "add lifestyle";
inline constexpr std::string_view kGetMatchTable = "get match table";
inline constexpr std::string_view kContextField = "context";
inline constexpr std::string_view kRequestField = "request";
inline constexpr std::string_view kIdField = "id";
inline constexpr std::string_view kAuthorIdField = "author_id";
inline constexpr std::string_view kTargetIdField = "target_id";
inline constexpr std::string_view kEmailField = "email";
inline constexpr std::string_view kResponseField = "response";
inline constexpr std::string_view kNoResponse = "no response"; 
inline constexpr std::string_view kIsBusyField = "is_busy";
inline constexpr std::string_view kReactionField = "reaction";
inline constexpr std::string_view kIsLikeField = "is_like";
inline constexpr std::string_view kErrorNoSuchObject = "Error: no such object!";
inline constexpr std::string_view kFormField = "form";
inline constexpr std::string_view  kIsTextChangedField = "is_text_changed";
inline constexpr std::string_view kInterestField = "interest";
inline constexpr std::string_view kLifestyleField = "lifestyle";


class IRequestHandler {
public:
  virtual std::string ReadRequest(std::string json) = 0;

private:
  virtual std::string RegistrationResponse(unsigned new_id) = 0;
  virtual std::string EmailCheckResponse(bool) = 0;
  virtual std::string LoginCheckResponse(bool) = 0;
  virtual std::string LogInResponse(std::shared_ptr<Profile>) = 0;
  virtual std::string LikeResponse() = 0;
  virtual std::string EditFormResponse() = 0;
  virtual std::string AddFormResponse() = 0;
  virtual std::string GetNextProfileResponse() = 0;
  virtual std::string GetPossibleLifestyleResponse(std::vector<Lifestyle>) = 0;
  virtual std::string GetPossibleInterestResponse(std::vector<Interest>) = 0;
  virtual std::string GetUserFormResponce(Form) = 0;
  virtual std::string GetMatchTableResponse(std::vector<Form> forms) = 0;
  virtual std::string AddInterestResponse() = 0;
  virtual std::string AddLifestyleResponse() = 0;
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
  virtual std::string LoginCheckResponse(bool) override;
  virtual std::string LogInResponse(std::shared_ptr<Profile>) override;
  virtual std::string LikeResponse() override;
  virtual std::string EditFormResponse() override;
  virtual std::string AddFormResponse() override;
  virtual std::string GetNextProfileResponse() override;
  virtual std::string GetPossibleLifestyleResponse(std::vector<Lifestyle>) override;
  virtual std::string GetPossibleInterestResponse(std::vector<Interest>) override;
  virtual std::string GetUserFormResponce(Form) override;
  virtual std::string GetMatchTableResponse(std::vector<Form> forms) override;
  virtual std::string AddInterestResponse() override;
  virtual std::string AddLifestyleResponse() override;
  void SaveRecommendation(std::vector<Form>& recommended_forms);
};
