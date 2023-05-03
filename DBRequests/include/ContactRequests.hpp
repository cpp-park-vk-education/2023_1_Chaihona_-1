#pragma once
#include "contact.hpp"
#include <string>
#include <vector>

class ContactRequests{
private: 
    unsigned userId;
    std::string contactType;
    std::string value;
public:
    ContactRequests() {};
    unsigned insert() {};  
    bool update() {};
    std::vector<Contact> selectUserContacts (unsigned userId) {};
};