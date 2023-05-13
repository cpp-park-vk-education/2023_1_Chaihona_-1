#pragma once

#include "user.hpp"
#include "profile.hpp"
#include "form.hpp"
#include "contact.hpp"
#include "match.hpp"
#include <vector>


class IDatabaseManager {
public:
    virtual unsigned addUser(User user) = 0;
    virtual bool checkIfEmailBusy(std::string email) = 0;
    virtual Profile authorise(User user) = 0;
    virtual unsigned addProfile(User user, Profile profile) = 0;
    virtual unsigned addForm(Profile profile, Form form) = 0;
    //bool editForm(Form form) {};
    virtual std::vector<Form> getRecommendForms(Form form) = 0;
    virtual Form getUserForm(Profile profile) = 0;
    virtual std::vector<Contact> getUserContacts(Form form) = 0;
    virtual unsigned insertMatch(Match match) = 0;
    virtual bool checkMatchResult(Form form1, Form form2) = 0;
};


class DBManager : public IDatabaseManager{
    unsigned addUser(User user);
    bool checkIfEmailBusy(std::string email);
    Profile authorise(User user);
    unsigned addProfile(User user, Profile profile);
    unsigned addForm(Profile profile, Form form) {return 1;};
    //bool editForm(Form form) {};
    std::vector<Form> getRecommendForms(Form form) {return std::vector<Form>();};
    Form getUserForm(Profile profile) {return Form();};
    std::vector<Contact> getUserContacts(Form form) {return std::vector<Contact>();};
    unsigned insertMatch(Match match);
    bool checkMatchResult(Form form1, Form form2);
};