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
    UserLifestyleRequests(unsigned _uid) : userId(_uid) {}
    UserLifestyleRequests(unsigned _uid, unsigned _lid, std::string _ch) : userId(_uid), lifestyleId(_lid), userChoice(_ch) {}
    unsigned insert(); 
    std::vector<UserLifestyle> getUserLifestyles();
    bool updateUserChoice(); 
};