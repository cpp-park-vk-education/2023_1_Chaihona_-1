#include "MatchRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>


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
