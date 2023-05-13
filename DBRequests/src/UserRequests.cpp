#include "UserRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>
#include <sstream>

unsigned UserRequests::insert() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("insert_user", std::make_format_args(login, password));
    auto result = dbWork.insert(request);
    std::cout << result << std::endl;
    return result;
}

unsigned UserRequests::authorise() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("authorise", std::make_format_args(login, password));
    auto result = dbWork.select(request);
    if (result.size()==0) return 0;
    else return std::stoi(result[0][0]);
}
