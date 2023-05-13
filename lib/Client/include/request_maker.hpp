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
inline constexpr std::string_view kEditFormRequest = "edit form";
inline constexpr std::string_view kContextField = "context";
inline constexpr std::string_view kRequestField = "request";
inline constexpr std::string_view kIdField = "id";
inline constexpr std::string_view kAuthorIdField = "author_id";
inline constexpr std::string_view kTargetIdField = "target_id";
inline constexpr std::string_view kEmailField = "email";
inline constexpr std::string_view kResponseField = "response";

class IRequestMaker {
public:
  virtual void MakeRequest(std::string json) = 0;
  virtual void Close() = 0;
};

class RequestMaker: public IRequestMaker {
public:

  RequestMaker(std::shared_ptr<IClient> cp);
  virtual void MakeRequest(std::string json) override;
  virtual void Close() override;

private:

  std::shared_ptr<IClient> client_ptr_;

};