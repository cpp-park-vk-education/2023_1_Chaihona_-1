#include "user.hpp"
#include "profile.hpp"
#include "form.hpp"
#include "contact.hpp"
#include <vector>

class DBManager{
    void addUser(User user) {};
    bool checkIfEmailBusy (std::string email) {};
    bool authorise (User user) {};
    bool addProfile (User user) {};
    bool addForm (Profile profile) {};
    void editForm (Form form) {};
    std::vector<Form> getRecommendForms(Form form) {};
    Form getUserForm (Form form) {};
    std::vector<Contact> getUserContacts (Form form) {};
};