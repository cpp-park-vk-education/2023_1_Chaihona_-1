#include "MatchRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>

std::vector<unsigned> splitDbArrayIntoUnsigned (std::string dbArray) {
    std::vector<unsigned> arrayValues;
    dbArray = dbArray.substr(1, dbArray.size()-2);
    std::stringstream ss(dbArray);
    std::string curr;
    while (std::getline(ss, curr, ',')) {
        arrayValues.push_back(std::stoi(curr));
    }
    return arrayValues;
}

bool MatchRequests::matchResult() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_match_result", std::make_format_args(firstId, secondId));
    auto result = dbWork.select(request);
    if (result[0][0]=="LIKE")
        return true;
    else
        return false;
}

unsigned MatchRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    std::string mType;
    SQLProvider sqlprov("../SQLTemplates/");
    if (match) 
        mType = "LIKE";
    else    
        mType = "DISLIKE";    
    auto request = sqlprov.getRequest("insert_match", std::make_format_args(mType, firstId, secondId));
    auto result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
}


std::vector<unsigned> MatchRequests::getUserMatches() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_matches", std::make_format_args(firstId));
    auto result = dbWork.select(request);
    auto matches = splitDbArrayIntoUnsigned(result[0][0]);
    return matches;
}