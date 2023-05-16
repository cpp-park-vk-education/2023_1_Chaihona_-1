#include "form.hpp"
#include "boost/json.hpp"
#include <iostream>

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Form const &form) {
    boost::json::array userLifestylesArr;
    boost::json::array userInterestsArr;
    for (auto &userLifestyle : form.getLifestyle()) {
        userLifestylesArr.emplace_back(boost::json::value_from(userLifestyle).as_object());
    }
    for (auto &userInterest : form.getInterests()) {
        userInterestsArr.emplace_back(boost::json::value_from(userInterest).as_object());
    }
    jv = {
        {"form_id", form.getId()},
        {"interests", userInterestsArr},
        {"lifestyle", userLifestylesArr},
        {"description", form.getDescription()},
        {"university", form.getUniversity()},
        {"career", form.getCareer()},
        {"location", form.getLocation()},
        {"age", form.getAge()},
        {"gender", form.getGender()},
        {"bday", form.getBdate()},
        {"preferences",(boost::json::value_from(form.getPreference()))},
    };
}


Form tag_invoke(boost::json::value_to_tag<Form>, boost::json::value const &jv) {
    std::cout << "reading user form" << std::endl;
    boost::json::object const &obj = jv.as_object();
    return Form{
        boost::json::value_to<unsigned>(obj.at("form_id")),
        boost::json::value_to<std::vector<UserInterest>>(obj.at("interests")),
        boost::json::value_to<std::vector<UserLifestyle>>(obj.at("lifestyle")),
        boost::json::value_to<std::string>(obj.at("description")),
        boost::json::value_to<std::string>(obj.at("university")),
        boost::json::value_to<std::string>(obj.at("career")),
        boost::json::value_to<std::string>(obj.at("location")),
        boost::json::value_to<unsigned>(obj.at("age")),
        boost::json::value_to<char>(obj.at("gender")),
        boost::json::value_to<std::string>(obj.at("bday")),
        boost::json::value_to<Preference>(obj.at("preferences"))};
}