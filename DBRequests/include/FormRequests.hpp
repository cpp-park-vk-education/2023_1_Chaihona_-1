#pragma once
#include <ctype.h>
#include <vector>
#include <string>
#include <vector>

#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"
#include "form.hpp"
#include "contact.hpp"

class FormRequests{
private:
    unsigned profileId;
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    FormRequests() {};    
    unsigned insert() {};
    bool update() {};
    Form getUserForm() {};
    std::vector<Form> selectRecForms() {};
};

