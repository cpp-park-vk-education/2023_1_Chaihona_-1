#pragma once
#include <ctype.h>
#include <vector>
#include <string>
#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"
#include "contact.hpp"

class Form{
private:
    Profile profile;
    unsigned id;
    std::vector<UserInterest> interests;
    std::vector<UserLifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    unsigned age;
public:
    Form() {};
    Form(unsigned _id, std::vector<UserInterest> _iv, std::vector<UserLifestyle> _lv, std::string _desc, std::string _un, std::string _carr, std::string _loc, unsigned _age) : id(_id), lifestyle(_lv), interests(_iv), description(_desc), university(_un), career(_carr), location(_loc), age(_age) {}    
    unsigned getId() const {return id;};
    Profile getProfile() {Profile profile; return profile;};
    std::vector<UserInterest> getInterests() const {return interests;};
    std::vector<UserLifestyle> getLifestyle() const {return lifestyle;};
    std::string getDescription() const {return description;};
    std::string getUniversity() const {return university;};
    std::string getCareer() const {return career;};
    std::string getLocation() const {return location;};
    unsigned getAge() const {return age;}
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Form const& form);
Form tag_invoke(boost::json::value_to_tag<Form>, boost::json::value const& jv);