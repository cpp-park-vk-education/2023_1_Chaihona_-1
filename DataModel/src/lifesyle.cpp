#include "lifestyle.hpp"

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Lifestyle const &lifestyle) {
    boost::json::array choicesArr;
    for (auto &choice: lifestyle.getVariants()) {
        choicesArr.emplace_back(choice);
    }
    jv = {
    {"id", lifestyle.getId()},
    {"name", lifestyle.getName()},
    {"description", lifestyle.getDescription()},
    {"possible choices", choicesArr}
  };
}

Lifestyle tag_invoke(boost::json::value_to_tag<Lifestyle>, boost::json::value const& jv) {
    return Lifestyle();
}

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserLifestyle const &lifestyle) {
    jv = {
    {"name", lifestyle.getLifestyle().getName()},
    {"description", lifestyle.getLifestyle().getDescription()},
    {"user choice", lifestyle.getUserChoice()}
  };
}

UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv) {
    return UserLifestyle();
}