#pragma once
#include "lifestyle.hpp"
#include <string>
#include <vector>
#include "profile.hpp"

class UserLifestyleRequests {
private:
    unsigned userId;
    unsigned lifestyleId;
    std::string userChoice;
public:
    UserLifestyleRequests() {};
    unsigned insert() {}; 
    std::vector<Lifestyle> getUserLifestyles(Profile profile) {};
    bool update() {}; 
};