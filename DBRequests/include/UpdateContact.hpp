#include "contact.hpp"

class UpdateContact {
private: 
    unsigned userId;
    std::string contactType;
    std::string value;
public:
    UpdateContact() {};
    bool exec() {};  
};