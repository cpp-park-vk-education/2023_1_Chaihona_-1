#pragma once
#include <string>
#include <memory>
#include <vector>
#include "profile.hpp"

class ProfileRequests{
private:
    std::string email;
    std::string firstName;
    std::string lastName;
    unsigned userId;
public:
    ProfileRequests (unsigned _uid) : userId(_uid) {}
    ProfileRequests (std::string _mail, std::string _fn, std::string _ln, unsigned _uid) : email(_mail), firstName(_fn), lastName(_ln), userId(_uid) {}
    unsigned insert();
    std::shared_ptr<Profile> selectUserProfile();
};