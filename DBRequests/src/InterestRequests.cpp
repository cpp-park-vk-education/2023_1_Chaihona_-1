#include "InterestRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>

std::vector<Interest> InterestRequests::getPossibleInterests() {
    std::vector<Interest> possibleInterests;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_possible_interests", std::make_format_args());
    auto result = dbWork.select(request);
    for (int i = 0; i < result.size(); i++) {
        Interest curr (std::stoi(result[i][2]), result[i][0], result[i][1]);
        possibleInterests.push_back(curr);
    }
    return possibleInterests;
}