#pragma once
#include <string>
#include <vector>

class ProfileRequests{
private:
    std::string email;
    std::string firstName;
    std::string lastName;
    unsigned userId;
public:
    ProfileRequests() {};  
    unsigned insert() {};
};