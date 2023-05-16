#include "CheckEmail.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>

bool CheckEmail::exec() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("check_email", std::make_format_args(email));
    std::cout << request << std::endl;
    auto result = dbWork.select(request);
    if (result[0][0]!="0")
        return true;
    else
        return false;
}