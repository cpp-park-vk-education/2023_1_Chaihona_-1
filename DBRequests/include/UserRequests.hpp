#pragma once
#include "user.hpp"
#include <string>
#include <vector>

class UserRequests{
private:
    std::string login;
    std::string password;
public:
    UserRequests(std::string _log, std::string _pass) : login(_log), password(_pass) {};
    unsigned insert();
    unsigned authorise();     
};