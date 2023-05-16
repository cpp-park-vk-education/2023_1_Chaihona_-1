#pragma once
#include <string>
#include <vector>
#include <boost/json.hpp>

class Contact {
private: 
    unsigned user_id;
    unsigned id;
    std::string contactType;
    std::string value;
public:
    Contact(unsigned _uid, std::string _ct, std::string _val) : user_id(_uid), contactType(_ct), value(_val) {}; 
    Contact(std::string _ct, std::string _val) : contactType(_ct), value(_val) {}; 
    unsigned getId() {return id;};
    std::string getContactType() const {return contactType;};
    std::string getContactValue() const {return value;};   
    unsigned getUserId() {return user_id;}
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Contact const& contact);
Contact tag_invoke(boost::json::value_to_tag<Contact>, boost::json::value const& jv);