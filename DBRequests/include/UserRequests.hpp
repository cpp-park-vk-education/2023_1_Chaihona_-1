#pragma once
#include "user.hpp"
#include <string>
#include <vector>

class UserRequests{
private:
    std::string login;
    std::string password;
public:
    UserRequests() {};
    unsigned insert(User user) {};
    unsigned authorise(User user) {};     
};