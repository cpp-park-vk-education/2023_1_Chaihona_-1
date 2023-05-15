#pragma once

#include <memory>
#include <string>
#include "client.hpp"

inline constexpr std::string_view kRegistrationRequest = "registration";
inline constexpr std::string_view kLogInRequest = "log in";
inline constexpr std::string_view kLogOutRequest = "log out";
inline constexpr std::string_view kEmailCheckRequest = "email check";
inline constexpr std::string_view kLikeRequest = "like";
inline constexpr std::string_view kDislikeRequest = "dislike";
inline constexpr std::string_view kGetNextProfileRequest = "get next profile";
inline constexpr std::string_view kGetPossibleInterestRequest = "get possible interest";
inline constexpr std::string_view kGetPossibleLifestyleRequest = "get possible lifestyle";
inline constexpr std::string_view kAddFormReqeust = "add form";
inline constexpr std::string_view kGetUserFormRequest = "get user form";
inline constexpr std::string_view kEditFormRequest = "edit form";
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
inline constexpr std::string_view kFormField = "form";
inline constexpr std::string_view  kIsTextChangedField = "is_text_changed";

class IRequestMaker {
public:
  virtual void MakeRequest(std::string json) = 0;
  virtual std::string getResponse(std::string request_type) = 0;
  virtual void Close() = 0;
};

class RequestMaker: public IRequestMaker {
public:

  RequestMaker(std::shared_ptr<IClient> cp);
  virtual void MakeRequest(std::string json) override;
  virtual std::string getResponse(std::string) override;
  virtual void Close() override;
private:
  std::shared_ptr<IClient> client_ptr_;

};