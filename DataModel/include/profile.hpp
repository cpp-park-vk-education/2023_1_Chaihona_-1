#pragma once
#include "user.hpp"

class Profile{
private:
    std::string email;
    std::string firstName;
    std::string lastName;
public:
    Profile();  
    std::string getEmail() {return std::string("zhena@zhizni.net");};
    std::string getFirstName() {return std::string("Gena");};
    std::string getLastName() {return std::string("Bukin");};      
};