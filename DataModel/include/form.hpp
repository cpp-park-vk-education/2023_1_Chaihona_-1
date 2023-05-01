#pragma once
#include <ctype.h>
#include <vector>

#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"

class Form{
private:
    Profile profile;
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    Form();    
    Profile getProfile();
    std::vector<Interest> getInterests();
    std::vector<Lifestyle> getLifestyl();
    std::string getDescription() {return std::string("Sample description");};
    std::string getUniversity() {return std::string("BMSTU");};
    std::string getCareer() {return std::string("Senior HTML Developer at VK");};
    std::string getLocation() {return std::string("Russia, Saint-Petersburg, Krestovsky island");};
};