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
    {"interest_id", interest.getId()},
    {"name", interest.getName()},
    {"description", interest.getDescription()}
  };
}

Interest tag_invoke(json::value_to_tag<Interest>, json::value const& jv) {
  Interest interest;
  boost::json::object const& obj = jv.as_object();
  return Interest{
    boost::json::value_to<unsigned>(obj.at("interest_id")),
    boost::json::value_to<std::string>(obj.at("name")),
    boost::json::value_to<std::string>(obj.at("description"))
  };
}


void tag_invoke(const json::value_from_tag&, json::value& jv, Lifestyle const& lifestyle) {
  jv = {
    {"lifestyle_id", lifestyle.getId()},
    {"name", lifestyle.getName()},
    {"description", lifestyle.getDescription()}//,
    //{"variants", lifestyle.getVariants()}
  };
}

Lifestyle tag_invoke(json::value_to_tag<Lifestyle>, json::value const& jv) {
  boost::json::object const& obj = jv.as_object();
  return Lifestyle{
    boost::json::value_to<unsigned>(obj.at("lifestyle_id")),
    boost::json::value_to<std::string>(obj.at("name")),
    boost::json::value_to<std::string>(obj.at("description")),
    boost::json::value_to<std::vector<std::string>>(obj.at("variants"))
  };
}


void tag_invoke(const json::value_from_tag&, json::value& jv, Contact const& contact) {
  jv = {
    {"contact_id", contact.getId()},
    {"user_id", contact.getUserId()},
    {"contactType", contact.getContactType()},
    {"value", contact.getContactValue()}
  };
}

Contact tag_invoke(json::value_to_tag<Contact>, json::value const& jv) {
  boost::json::object const& obj = jv.as_object();
  return Contact{
    boost::json::value_to<unsigned>(obj.at("contact_id")),
    boost::json::value_to<unsigned>(obj.at("user_id")),
    boost::json::value_to<std::string>(obj.at("contactType")),
    boost::json::value_to<std::string>(obj.at("value"))
  };
}


void tag_invoke(const json::value_from_tag&, json::value& jv, Form const& form) {
  jv = {
    {"form_id", form.getId()},
    {"interests",  boost::json::value_from(form.getInterests())},
    {"lifestyle",  boost::json::value_from(form.getLifestyle())},
    {"contact",  boost::json::value_from(form.getContacts())},
    {"description", form.getDescription()},
    {"university", form.getUniversity()},
    {"career", form.getCareer()},
    {"location", form.getLocation()}
  };
}

Form tag_invoke(json::value_to_tag<Form>, json::value const& jv){
  Form form;
  boost::json::object const& obj = jv.as_object();
  return Form{
    boost::json::value_to<unsigned>(obj.at("form_id")),
    boost::json::value_to<std::vector<Interest>>(obj.at("interests")),
    boost::json::value_to<std::vector<Lifestyle>>(obj.at("lifestyle")),
    boost::json::value_to<std::vector<Contact>>(obj.at("contact")),
    boost::json::value_to<std::string>(obj.at("description")),
    boost::json::value_to<std::string>(obj.at("university")),
    boost::json::value_to<std::string>(obj.at("career")),
    boost::json::value_to<std::string>(obj.at("location"))
  };
}

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserInterest const &interest) {
    jv = {
    {"name", interest.getInterest().getName()},
    {"description", interest.getInterest().getDescription()},
    {"user rate", interest.getRate()}
  };
}

UserInterest tag_invoke(boost::json::value_to_tag<UserInterest>, boost::json::value const& jv) {
  return UserInterest{};
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