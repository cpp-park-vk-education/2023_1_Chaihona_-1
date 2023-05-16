#include "UserLifestyleRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>


unsigned UserLifestyleRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_user_lifestyle", std::make_format_args(userChoice, userId, lifestyleId));
    auto result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
    return 0;
}


std::vector<UserLifestyle> UserLifestyleRequests::getUserLifestyles() {
    std::vector<UserLifestyle> userLifestyles;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_lifestyles", std::make_format_args(userId));
    auto result = dbWork.select(request);
    for (int i = 0; i < result.size(); i++) {
        Lifestyle currLifestyle (std::stoi(result[i][3]),result[i][4],result[i][5],splitDbArray(result[i][6]));
        UserLifestyle currUserLifestyle (std::stoi(result[i][2]), currLifestyle, result[i][0]);
        userLifestyles.push_back(currUserLifestyle);
    }
    return userLifestyles;
}

bool UserLifestyleRequests::updateUserChoice() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("update_user_lifestyle_choice", std::make_format_args(userChoice, userId, lifestyleId));
    dbWork.update(request);
    return true;
}
