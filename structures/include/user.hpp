#pragma once
#include <string>
#include <boost/json.hpp>


namespace json = boost::json;

struct User {
  std::string login;
  std::string password;
};

void tag_invoke(const json::value_from_tag&, json::value& jv, User const& user);

User tag_invoke(json::value_to_tag<User>, json::value const& jv);

struct Profile {
  std::string first_name;
  std::string last_name;
  User user;
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Profile const& profile);

Profile tag_invoke(json::value_to_tag<Profile>, json::value const& jv);