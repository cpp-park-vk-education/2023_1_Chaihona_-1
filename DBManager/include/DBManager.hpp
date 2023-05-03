#include "user.hpp"
#include "profile.hpp"
#include "form.hpp"
#include "contact.hpp"
#include <vector>

class DBManager{
    unsigned addUser(User user) {};
    bool checkIfEmailBusy(std::string email) {};
    Profile authorise(User user) {};
    unsigned addProfile(User user, Profile profile) {};
    unsigned addForm(Profile profile, Form form) {};
    bool editForm(Form form) {};
    std::vector<Form> getRecommendForms(Form form) {};
    Form getUserForm(Profile profile) {};
    std::vector<Contact> getUserContacts(Form form) {};
    unsigned insertMatch(Profile profile1, Profile profile2) {};
    bool checkMatchResukt(Profile profile1, Profile profile2) {};
};