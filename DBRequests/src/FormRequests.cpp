#include "FormRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>
#include "UserInterestRequests.hpp"
#include "UserLifestyleRequests.hpp"

Form FormRequests::getUserForm() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_form", std::make_format_args(profileId));
    auto result = dbWork.select(request);
    unsigned id = std::stoi(result[0][0]);
    UserInterestRequests uireq (id);
    UserLifestyleRequests ulreq (id);
    auto userInterests = uireq.getUserInterests();
    auto userLifestyles = ulreq.getUserLifestyles();
    Form form (id,userInterests, userLifestyles, result[0][1], result[0][2], result[0][3], result[0][4], std::stoi(result[0][5]));
    return form;
}