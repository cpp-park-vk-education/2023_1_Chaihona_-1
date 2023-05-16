#pragma once
#include <ctype.h>
#include <vector>
#include <string>
#include <vector>

#include "profile.hpp"
#include "interest.hpp"
#include "lifestyle.hpp"
#include "form.hpp"
#include "preference.hpp"
#include "contact.hpp"

class FormRequests{
private:
    unsigned profileId;
    std::vector<UserInterest> interests;
    std::vector<UserLifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    Preference preference;
    unsigned userId;
    std::string bdate;
    unsigned age;
    char gender;
public:
    FormRequests() {};    
    FormRequests (unsigned _profileId) : profileId(_profileId) {};
    FormRequests (std::vector<UserInterest> _iv, std::vector<UserLifestyle> _lv, std::string _desc, std::string _un, std::string _carr, std::string _loc, std::string _bdate, Preference _pref, unsigned _profileId, char _gender) : lifestyle(_lv), interests(_iv), description(_desc), university(_un), career(_carr), location(_loc), bdate(_bdate), preference(_pref),  profileId(_profileId), gender(_gender) {}
    FormRequests (Preference _pref, unsigned _age, char _gender, std::string _loc, unsigned _uid) : preference(_pref), age(_age), gender(_gender), location(_loc), userId(_uid) {};
    unsigned insert();
    Form getUserForm();
    Form getFormById();
    std::vector<Form> selectRecForms();
    std::vector<std::pair<Form, std::vector<Contact>>> selectMatchContacts();
};

