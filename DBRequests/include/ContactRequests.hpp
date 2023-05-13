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
    ContactRequests(unsigned _uid) : userId(_uid) {};
    ContactRequests(unsigned _uid, std::string _ct, std::string _val) : userId(_uid), contactType(_ct), value(_val) {};
    unsigned insert();  
    bool updateContactValue();
    std::vector<Contact> selectUserContacts ();
};