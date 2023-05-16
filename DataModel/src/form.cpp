#include "form.hpp"
#include "boost/json.hpp"

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Form const& form) {
    boost::json::array userLifestylesArr;
    boost::json::array userInterestsArr;
    for (auto &userLifestyle: form.getLifestyle()) {
        userLifestylesArr.emplace_back(boost::json::value_from(userLifestyle).as_object());
    }
    for (auto &userInterest: form.getInterests()) {
        userInterestsArr.emplace_back(boost::json::value_from(userInterest).as_object());
    }
    jv = {
    {"id", form.getId()},
    {"interests", userInterestsArr},
    {"lifestyle", userLifestylesArr},
    {"description", form.getDescription()},
    {"university", form.getUniversity()},
    {"career", form.getCareer()},
    {"location", form.getLocation()},
    {"age", form.getAge()},
  };
}

Form tag_invoke(boost::json::value_to_tag<Form>, boost::json::value const& jv) {
    return Form();
}