#include "contact.hpp"
#include <vector>

class SelectUserContacts {
private:
    unsigned userId;
public:
    SelectUserContacts() {};
    std::vector<Contact> exec() {};    
};