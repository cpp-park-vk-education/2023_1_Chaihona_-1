#include "user.hpp"

void tag_invoke(const json::value_from_tag&, json::value& jv, User const& user) {
  jv = {
    {"login", user.login},
    {"password", user.password}
  };
}

User tag_invoke(json::value_to_tag<User>, json::value const& jv) {
  User user;
  json::object const& obj = jv.as_object();
  // extract(obj, user.login, "login");
  // extract(obj, user.password, "password");
  return User{
    json::value_to<std::string>(obj.at("login")),
    json::value_to<std::string>(obj.at("password"))
  };
}

void tag_invoke(const json::value_from_tag&, json::value& jv, Profile const& profile) {
  jv = {
    {"user", json::value_from(profile.user)},
    {"first_name", profile.first_name},
    {"last_name", profile.last_name}
  };
}

Profile tag_invoke(json::value_to_tag<Profile>, json::value const& jv) {
  Profile profile;
  json::object const& obj = jv.as_object();
  //obj.at("user");
  return Profile{
    json::value_to<std::string>(obj.at("user")),
    json::value_to<std::string>(obj.at("first_name")),
    json::value_to<std::string>(obj.at("last_name"))
  };
}