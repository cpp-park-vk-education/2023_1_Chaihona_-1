#pragma once
#include "user.hpp"
#include <string>
#include <vector>

class Profile{
private:
    unsigned id;
    User user;
    std::string email;
    std::string firstName;
    std::string lastName;
public:
    Profile() {};  
    unsigned getId() {return 1;};
    User getUser() {User user; return user;}
    std::string getEmail() {return std::string("zhena@zhizni.net");};
    std::string getFirstName() {return std::string("Gena");};
    std::string getLastName() {return std::string("Bukin");};      
};