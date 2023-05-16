#include "DBManager.hpp"
#include "UserRequests.hpp"
#include "CheckEmail.hpp"
#include "ProfileRequests.hpp"
#include "MatchRequests.hpp"
#include "InterestRequests.hpp"
#include "LifestyleRequests.hpp"
#include "PreferencesRequests.hpp"
#include "FormRequests.hpp"

unsigned DBManager::addUser(User user) {
    UserRequests ureq(user.getLogin(), user.getPassword());
    return ureq.insert();
}

bool DBManager::checkIfEmailBusy(std::string email) {
    CheckEmail emailReq(email);
    return emailReq.exec();
}

std::shared_ptr<Profile> DBManager::authorise(User user) {
    UserRequests ureq(user.getLogin(), user.getPassword());
    unsigned id = ureq.authorise();
    ProfileRequests preq(id);
    auto userProfile = preq.selectUserProfile();
    if (userProfile)
        userProfile->setUser(user);
    return userProfile;
}

unsigned DBManager::addProfile(User user, Profile profile) {
    ProfileRequests preq (profile.getEmail(), profile.getFirstName(), profile.getLastName(), user.getId());
    return preq.insert();
}

Form DBManager::getUserForm(unsigned id) {
    FormRequests freq(id);
    return freq.getUserForm();
}

unsigned DBManager::insertMatch(Match match)
{
    MatchRequests mreq(match.getForm1Id(), match.getForm2Id(),match.getType());
    return mreq.insert();
}

std::vector<Interest> DBManager::getPossibleInterest() {
    InterestRequests ireq;
    return ireq.getPossibleInterests();
}


std::vector<Lifestyle> DBManager::getPossibleLifestyles() {
    LifestyleRequests lsreq;
    return lsreq.getPossibleLifestyles();
}


Preference DBManager::getUserPreferences(unsigned formId) {
    PreferencesRequests preq (formId);
    return preq.getUserPreferences();
}
