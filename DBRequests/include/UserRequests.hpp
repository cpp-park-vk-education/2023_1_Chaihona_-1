#pragma once
#include "user.hpp"


class UserRequests{
private:
    std::string login;
    std::string password;
public:
    UserRequests() {};
    unsigned insert() {};
    unsigned authorise() {};     
};