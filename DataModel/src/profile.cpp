#include "profile.hpp"

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Profile const& profile) {
  jv = {
    {"profile_id", profile.getId()},
    {"user", boost::json::value_from(profile.getUser())},
    {"email", boost::json::value_from(profile.getEmail())},
    {"first_name", profile.getFirstName()},
    {"last_name", profile.getLastName()}
  };
}

Profile tag_invoke(boost::json::value_to_tag<Profile>, boost::json::value const& jv) {
  Profile profile;
  boost::json::object const& obj = jv.as_object();
  return Profile{
    boost::json::value_to<unsigned>(obj.at("profile_id")),
    boost::json::value_to<User>(obj.at("user")),
    boost::json::value_to<std::string>(obj.at("email")),
    boost::json::value_to<std::string>(obj.at("first_name")),
    boost::json::value_to<std::string>(obj.at("last_name"))
  };
}