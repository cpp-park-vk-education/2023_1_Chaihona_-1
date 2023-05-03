#pragma once
#include "interest.hpp"
#include <string>
#include <vector>
#include "profile.hpp"

class UserInterestRequests {
private:
    unsigned userId;
    unsigned interestId;
    unsigned rate;
public:
    UserInterestRequests() {};
    unsigned insert() {};
    std::vector<Interest> getUserInterests (Profile profile) {}; 
    bool update() {};
};