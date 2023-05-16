#pragma once

#include "user.hpp"
#include "profile.hpp"
#include "form.hpp"
#include "contact.hpp"
#include "match.hpp"
#include <memory>
#include <vector>
#include "preference.hpp"


class IDatabaseManager {
public:
    virtual unsigned addUser(User user) = 0;
    virtual bool checkIfEmailBusy(std::string email) = 0;
    virtual std::shared_ptr<Profile> authorise(User user) = 0;
    virtual unsigned addProfile(User user, Profile profile) = 0;
    virtual unsigned addForm(Profile profile, Form form) = 0;
    //bool editForm(Form form) {};
    virtual std::vector<Form> getRecommendForms(Form form) = 0;
    virtual Form getUserForm(unsigned id) = 0;
    virtual std::vector<Contact> getUserContacts(Form form) = 0;
    virtual unsigned insertMatch(Match match) = 0;
    virtual std::vector<Interest> getPossibleInterest() = 0;
    virtual std::vector<Lifestyle> getPossibleLifestyles() = 0;
    virtual Preference getUserPreferences(unsigned formId) = 0;
    //virtual bool checkMatchResult(Form form1, Form form2) = 0;
};


class DBManager : public IDatabaseManager{
    unsigned addUser(User user);
    bool checkIfEmailBusy(std::string email);
    std::shared_ptr<Profile> authorise(User user);
    unsigned addProfile(User user, Profile profile);
    unsigned addForm(Profile profile, Form form) {return 1;};
    //bool editForm(Form form) {};
    std::vector<Form> getRecommendForms(Form form) { std::vector<Form> formVector; Form form1; Form form2; formVector.push_back(form1); formVector.push_back(form2); return formVector; };
    virtual Form getUserForm(unsigned id) override;
    std::vector<Contact> getUserContacts(Form form) {return std::vector<Contact>();};
    unsigned insertMatch(Match match);
    virtual std::vector<Interest> getPossibleInterest() override;
    virtual std::vector<Lifestyle> getPossibleLifestyles() override;
    virtual Preference getUserPreferences(unsigned formId) override;
   // bool checkMatchResult(Form form1, Form form2);
};