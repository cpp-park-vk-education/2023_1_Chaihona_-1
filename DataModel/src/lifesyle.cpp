#include "lifestyle.hpp"
#include <iostream>

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
  boost::json::object const& obj = jv.as_object();
  return Lifestyle{
    boost::json::value_to<unsigned>(obj.at("id")),
    boost::json::value_to<std::string>(obj.at("name")),
    boost::json::value_to<std::string>(obj.at("description")),
    boost::json::value_to<std::vector<std::string>>(obj.at("possible choices"))
  };
}

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserLifestyle const &lifestyle) {
    jv = {
    {"lifestyle", boost::json::value_from(lifestyle.getLifestyle())},
    {"user choice", lifestyle.getUserChoice()}
  };
}

UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv) {
    std::cout << "reading user lifestyle" << std::endl;
    boost:: json::object const& obj = jv.as_object();
    return UserLifestyle {
        0,
        boost::json::value_to<Lifestyle>(obj.at("lifestyle")),
        boost::json::value_to<std::string>(obj.at("user choice"))
    };
}