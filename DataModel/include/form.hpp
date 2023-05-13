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
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    Form() {};    
    unsigned getId() {return 1;};
    Profile getProfile() {Profile profile; return profile;};
    std::vector<Interest> getInterests() {std::vector<Interest> result; Interest interest; result.push_back(interest); return result;};
    std::vector<Lifestyle> getLifestyle() {std::vector<Lifestyle> result; Lifestyle lifestyle; result.push_back(lifestyle); return result;};
  //  std::vector<Contact> getContacts() {std::vector<Contact> result; Contact contact; result.push_back(contact); return result;}
    std::string getDescription() {return std::string("Sample description");};
    std::string getUniversity() {return std::string("BMSTU");};
    std::string getCareer() {return std::string("Senior HTML Developer at VK");};
    std::string getLocation() {return std::string("Russia, Saint-Petersburg, Krestovsky island");};
};