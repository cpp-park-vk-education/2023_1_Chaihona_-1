#include "preference.hpp"

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Preference const& preference) {
    jv = {
    {"min_age", preference.getMinAge()},
    {"max_age", preference.getMaxAge()},
    {"radius", preference.getRadius()},
    {"gender", preference.getGender()}
  };
}


Preference tag_invoke(boost::json::value_to_tag<Preference>, boost::json::value const& jv) {
  boost:: json::object const& obj = jv.as_object();
  return Preference{
    boost::json::value_to<unsigned>(obj.at("min_age")),
    boost::json::value_to<unsigned>(obj.at("max_age")),
    boost::json::value_to<unsigned>(obj.at("radius")),
    boost::json::value_to<char>(obj.at("gender")),
  };
}