#include "user.hpp"

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, User const& user) {
  jv = {
    {"user_id", user.getId()},
    {"login", user.getLogin()},
    {"password", user.getPassword()}
  };
}

User tag_invoke(boost::json::value_to_tag<User>, boost::json::value const& jv) {
  User user;
 boost:: json::object const& obj = jv.as_object();
  return User{
    boost::json::value_to<unsigned>(obj.at("user_id")),
    boost::json::value_to<std::string>(obj.at("login")),
    boost::json::value_to<std::string>(obj.at("password"))
  };
}


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


void tag_invoke(const json::value_from_tag&, json::value& jv, Interest const& interest) {
  jv = {
    {"id", interest.getId()},
    {"name", interest.getName()},
    {"description", interest.getDescription()}
  };
}

Interest tag_invoke(json::value_to_tag<Interest>, json::value const& jv) {
  Interest interest;
  boost::json::object const& obj = jv.as_object();
  return Interest{
    boost::json::value_to<unsigned>(obj.at("id")),
    boost::json::value_to<std::string>(obj.at("name")),
    boost::json::value_to<std::string>(obj.at("description"))
  };
}


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



void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, Contact const &contact) {
    jv = {
        {"contact type", contact.getContactType()},
        {"value", contact.getContactValue()}
    };
}

Contact tag_invoke(boost::json::value_to_tag<Contact>, boost::json::value const& jv) {
    boost::json::object const &obj = jv.as_object();
    return Contact{
        boost::json::value_to<std::string>(obj.at("contact type")),
        boost::json::value_to<std::string>(obj.at("value"))
    };
}
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
        boost::json::value_to<Preference>(obj.at("preferences")),
        };
}


void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserInterest const &interest) {
    jv = {
    {"interest", boost::json::value_from(interest.getInterest())},
    {"user rate", interest.getRate()}
  };
}

UserInterest tag_invoke(boost::json::value_to_tag<UserInterest>, boost::json::value const& jv) {
    boost:: json::object const& obj = jv.as_object();
    return UserInterest {
        boost::json::value_to<Interest>(obj.at("interest")),
        boost::json::value_to<unsigned>(obj.at("user rate"))
    };
}


void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserLifestyle const &lifestyle) {
    jv = {
    {"lifestyle", boost::json::value_from(lifestyle.getLifestyle())},
    {"user choice", lifestyle.getUserChoice()}
  };
}

UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv) {
    boost:: json::object const& obj = jv.as_object();
    return UserLifestyle {
        0,
        boost::json::value_to<Lifestyle>(obj.at("lifestyle")),
        boost::json::value_to<std::string>(obj.at("user choice"))
    };
}