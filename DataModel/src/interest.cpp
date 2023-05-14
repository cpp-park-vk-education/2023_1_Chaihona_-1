#include "interest.hpp"

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Interest const &interest) {
    jv = {
    {"id", interest.getId()},
    {"name", interest.getName()},
    {"description", interest.getDescription()}
  };
}

Interest tag_invoke(boost::json::value_to_tag<Interest>, boost::json::value const& jv) {
  Interest interest;
  boost::json::object const &obj = jv.as_object();
  return Interest{
      boost::json::value_to<unsigned>(obj.at("id")),
      boost::json::value_to<std::string>(obj.at("name")),
      boost::json::value_to<std::string>(obj.at("description"))};
}

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserInterest const &interest) {
    jv = {
    {"name", interest.getInterest().getName()},
    {"description", interest.getInterest().getDescription()},
    {"user rate", interest.getRate()}
  };
}

UserInterest tag_invoke(boost::json::value_to_tag<UserInterest>, boost::json::value const& jv) {
  return UserInterest();
}