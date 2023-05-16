#include "ContactRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>


unsigned ContactRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_contact", std::make_format_args(contactType, value));
    auto result = dbWork.insert(request);
    request = sqlprov.getRequest("insert_user_contact", std::make_format_args(userId, result));
    result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
}

bool ContactRequests::updateContactValue() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_contact_id", std::make_format_args(userId, contactType));
    auto result = dbWork.select(request);
    unsigned contactId = std::stoi(result[0][0]);
    request = sqlprov.getRequest("update_contact_value", std::make_format_args(value, contactId));
    dbWork.update(request);
    return true;
}

std::vector<Contact> ContactRequests::selectUserContacts() {
    std::vector<Contact> userContacts;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_contacts", std::make_format_args(userId));
    auto result = dbWork.select(request);
    for (int i = 0; i < result.size(); i++) {
        Contact curr (userId, result[i][1], result[i][2]);
        userContacts.push_back(curr);
    }
    return userContacts;
}