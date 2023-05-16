#include "LifestyleRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>
#include <sstream>

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


std::vector<Lifestyle> LifestyleRequests::getPossibleLifestyles() {
    std::vector<Lifestyle> possibleLifestyles;
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_possible_lifestyles", std::make_format_args());
    auto result = dbWork.select(request);
    for (int i = 0; i < result.size(); i++) {
        Lifestyle curr (std::stoi(result[i][3]), result[i][0], result[i][i], splitDbArray(result[i][2]));
        possibleLifestyles.push_back(curr);
    }
    return possibleLifestyles;
}