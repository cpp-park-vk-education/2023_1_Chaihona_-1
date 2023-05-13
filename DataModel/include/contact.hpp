#pragma once
#include <string>
#include <vector>

class Contact {
private: 
    unsigned user_id;
    unsigned id;
    std::string contactType;
    std::string value;
public:
    Contact(unsigned _uid, std::string _ct, std::string _val) : user_id(_uid), contactType(_ct), value(_val) {}; 
    unsigned getId() {return 1;};
    std::string getContactType() {return contactType;};
    std::string getContactValue() {return value;};   
    unsigned getUserId() {return user_id;}
};