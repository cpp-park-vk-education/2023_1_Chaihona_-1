#include "ProfileRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>
#include <sstream>

unsigned ProfileRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_profile", std::make_format_args(email, firstName, lastName, userId));
    auto result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
}

std::shared_ptr<Profile> ProfileRequests::selectUserProfile() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("select_user_profile", std::make_format_args(userId));
    auto result = dbWork.select(request);
    if (result.size()!=0) {
        std::cout << "Got result!" << std::endl;
        auto profileValues = result[0];
        return std::shared_ptr<Profile> (new Profile(std::stoi(profileValues[3]),profileValues[0], profileValues[1], profileValues[2]));
    } else {
        std::cout << "No result!" << std::endl;
        return nullptr;
    }
}
