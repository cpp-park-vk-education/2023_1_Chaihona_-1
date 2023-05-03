#include "contact.hpp"

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