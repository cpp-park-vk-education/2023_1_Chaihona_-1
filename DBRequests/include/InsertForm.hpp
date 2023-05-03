#include <ctype.h>
#include <vector>

#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"
#include "contact.hpp"

class InsertForm{
private:
    Profile profile;
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    InsertForm() {};    
    bool exec() {};
};