#include <format>

#include "FormRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include "UserInterestRequests.hpp"
#include "UserLifestyleRequests.hpp"
#include "MatchRequests.hpp"
#include "ContactRequests.hpp"


Form FormRequests::getUserForm()
{
    auto dbConn = new DBConnection;
    DBWork dbWork(dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_form", std::make_format_args(profileId));
    auto result = dbWork.select(request);
    unsigned id = std::stoi(result[0][0]);
    UserInterestRequests uireq(id);
    UserLifestyleRequests ulreq(id);
    auto userInterests = uireq.getUserInterests();
    auto userLifestyles = ulreq.getUserLifestyles();
    Form form(id, userInterests, userLifestyles, result[0][1], result[0][2], result[0][3], result[0][4], std::stoi(result[0][5]));
    return form;
}

Form FormRequests::getFormById() {
    auto dbConn = new DBConnection;
    DBWork dbWork(dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_form_by_id", std::make_format_args(profileId));
    auto result = dbWork.select(request);
    unsigned id = std::stoi(result[0][0]);
    UserInterestRequests uireq(id);
    UserLifestyleRequests ulreq(id);
    auto userInterests = uireq.getUserInterests();
    auto userLifestyles = ulreq.getUserLifestyles();
    Form form(id, userInterests, userLifestyles, result[0][1], result[0][2], result[0][3], result[0][4], std::stoi(result[0][5]));
    return form;
}

std::vector<Form> FormRequests::selectRecForms() {
    std::vector<Form> recForms;
    auto dbConn = new DBConnection;
    DBWork dbWork(dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_rec_forms", std::make_format_args(userId, age, age, gender, location, preference.getMinAge(), preference.getMaxAge(), preference.getGender()));
    auto result = dbWork.select(request);
    for (unsigned i = 0; i < result.size(); i++) {
        unsigned id = std::stoi(result[i][0]);
        UserInterestRequests uireq(id);
        UserLifestyleRequests ulreq(id);
        auto userInterests = uireq.getUserInterests();
        auto userLifestyles = ulreq.getUserLifestyles();
        Form form(id, userInterests, userLifestyles, result[i][1], result[i][2], result[i][3], result[i][4], std::stoi(result[i][5]));
        recForms.push_back(form);
    }
    return recForms;
}


std::vector<std::pair<Form, std::vector<Contact>>> FormRequests::selectMatchContacts() {
    std::vector<std::pair<Form, std::vector<Contact>>> matchContacts;
    MatchRequests mreq(profileId);
    auto matchForms = mreq.getUserMatches();
    for (unsigned i = 0; i < matchForms.size(); i++) {
        FormRequests freq (matchForms[i]);
        ContactRequests creq (matchForms[i]);
        auto matchForm = freq.getFormById();
        auto matchFormContacts = creq.selectUserContacts();
        auto matchContact = std::make_pair(matchForm, matchFormContacts);
        matchContacts.push_back(matchContact);
    }
    return matchContacts;
}



unsigned FormRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork(dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_form", std::make_format_args(description, university, career, location, bdate,profileId, gender));
    std::cout << request << std::endl;
    auto result = dbWork.insert(request);
   auto prefRequest = sqlprov.getRequest("insert_preference", std::make_format_args(result, preference.getMinAge(), preference.getMaxAge(), preference.getRadius(), preference.getGender()));
   std::cout << prefRequest << std::endl;
   dbWork.insert(prefRequest);
    for (int i = 0; i < lifestyle.size(); i++) {
        UserLifestyleRequests ulreq(result, lifestyle[i].getLifestyle().getId(), lifestyle[i].getUserChoice());
        ulreq.insert();
    }
    for (int i = 0; i < interests.size(); i++) {
        UserInterestRequests uireq(result, interests[i].getInterest().getId(), interests[i].getRate());
        uireq.insert();
    }
    return result;
}