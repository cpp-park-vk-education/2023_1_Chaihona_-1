#include "UserLifestyleRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>


std::vector<std::string> splitDbArray (std::string dbArray) {
    std::vector<std::string> arrayValues;
    dbArray = dbArray.substr(1, dbArray.size()-2);
    std::stringstream ss(dbArray);
    std::string curr;
    while (std::getline(ss, curr, ',')) {
        arrayValues.push_back(curr.substr(1, curr.size()-2));
    }
    return arrayValues;
}

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
