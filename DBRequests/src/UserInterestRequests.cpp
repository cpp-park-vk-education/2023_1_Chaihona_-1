#include "UserInterestRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>

unsigned UserInterestRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_user_interest", std::make_format_args(rate ,userId, interestId));
    auto result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
    return 0;
}

std::vector<UserInterest> UserInterestRequests::getUserInterests() {
    std::vector<UserInterest> userInterests;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_interests", std::make_format_args(userId));
    auto result = dbWork.select(request);
    for (int i = 0; i < result.size(); i++) {
        Interest currInterest (std::stoi(result[i][3]),result[i][4],result[i][5]);
        UserInterest currUserInterest(std::stoi(result[i][2]), currInterest, std::stoi(result[i][0]), std::stoi(result[i][1]));
        userInterests.push_back(currUserInterest);
    }
    return userInterests;
}

bool UserInterestRequests::updateUserRate() {
    std::vector<UserInterest> userInterests;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("update_user_interest_rate", std::make_format_args(rate,userId, interestId));
    dbWork.update(request);
    return true;
}
