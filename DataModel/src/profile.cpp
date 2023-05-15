#include "profile.hpp"

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Profile const &profile) {
    jv = {
        {"email", profile.getEmail()},
        {"firstName", profile.getFirstName()},
        {"lastName", profile.getLastName()}};
}

Profile tag_invoke(boost::json::value_to_tag<Profile>, boost::json::value const &jv) {
  Profile profile;
  boost::json::object const &obj = jv.as_object();
  return Profile{
      boost::json::value_to<std::string>(obj.at("email")),
      boost::json::value_to<std::string>(obj.at("firstName")),
      boost::json::value_to<std::string>(obj.at("lastName"))};
}