#pragma once
#include "interest.hpp"
#include <string>
#include <vector>
#include "profile.hpp"

class UserInterestRequests {
private:
    unsigned userInterestId;
    unsigned userId;
    unsigned interestId;
    unsigned rate;
public:
    UserInterestRequests(unsigned _uid) : userId(_uid) {}
    UserInterestRequests(unsigned _uid, unsigned _iid, unsigned _rate) : userId(_uid), interestId(_iid), rate(_rate) {}
    unsigned insert();
    std::vector<UserInterest> getUserInterests (); 
    bool updateUserRate();
};