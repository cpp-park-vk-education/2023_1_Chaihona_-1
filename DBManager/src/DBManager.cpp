#include "DBManager.hpp"
#include "UserRequests.hpp"
#include "CheckEmail.hpp"
#include "ProfileRequests.hpp"
#include "MatchRequests.hpp"


unsigned DBManager::addUser(User user) {
    UserRequests ureq(user.getLogin(), user.getPassword());
    return ureq.insert();
}

bool DBManager::checkIfEmailBusy(std::string email) {
    CheckEmail emailReq(email);
    return emailReq.exec();
}

Profile DBManager::authorise(User user) {
    UserRequests ureq(user.getLogin(), user.getPassword());
    unsigned id = ureq.authorise();
    ProfileRequests preq(id);
    auto userProfile = preq.selectUserProfile();
    userProfile.setUser(user);
    return userProfile;
}

unsigned DBManager::addProfile(User user, Profile profile) {
    ProfileRequests preq (profile.getEmail(), profile.getFirstName(), profile.getLastName(), user.getId());
    return preq.insert();
}

unsigned DBManager::insertMatch(Match match) {
    MatchRequests mreq(match.getForm1().getId(), match.getForm2().getId(),match.getType());
    mreq.insert();
}

bool DBManager::checkMatchResult(Form form1, Form form2) {
    MatchRequests mreq(form1.getId(), form2.getId());
    return mreq.matchResult();
}
