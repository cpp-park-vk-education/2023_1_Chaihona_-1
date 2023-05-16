#include "PreferencesRequests.hpp"
#include "DBConnection.hpp"
#include "DBWork.hpp"
#include "SQLProvider.hpp"
#include <format>

Preference PreferencesRequests::getUserPreferences() {
    auto dbConn = new DBConnection;
    DBWork dbWork (dbConn);
    SQLProvider sqlprov("../SQLTemplates/");
    auto request = sqlprov.getRequest("get_user_preferences", std::make_format_args(formId));
    auto result = dbWork.select(request);
    return Preference(std::stoi(result[0][0]), std::stoi(result[0][1]), std::stoi(result[0][2]), result[0][3][0]);
}