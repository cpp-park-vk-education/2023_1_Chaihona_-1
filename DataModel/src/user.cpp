#include "user.hpp"


void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, User const& user) {
  jv = {
    {"login", user.getLogin()},
    {"password", user.getPassword()}
  };
}

User tag_invoke(boost::json::value_to_tag<User>, boost::json::value const& jv) {
 boost:: json::object const& obj = jv.as_object();
  return User{
    boost::json::value_to<std::string>(obj.at("login")),
    boost::json::value_to<std::string>(obj.at("password"))
  };
}