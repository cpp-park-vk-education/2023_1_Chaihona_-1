#include "DBWork.hpp"
#include <iostream>

std::vector<std::vector<std::string>> DBWork::select(std::string sql) {
    dbConnection->enter(true); 
    std::vector<std::vector<std::string>> out;
    auto res = dbConnection->cursor->exec(sql);
    for (auto const &row: res) {
        std::vector<std::string> curRow;
        for (auto const &val: row) {
            curRow.push_back(val.as<std::string>());
        }
        out.push_back(curRow);
    }
    dbConnection->exit(); 
    return out;
}

void DBWork::update(std::string sql) {
    dbConnection->enter(true); 
    dbConnection->cursor->exec(sql);
    dbConnection->exit(); 
}

int DBWork::insert(std::string sql) {
    dbConnection->enter(true);
    int newObjId;
    auto res = dbConnection->cursor->exec(sql);
    newObjId = res[0][0].as<int>();
    dbConnection->exit(); 
    return newObjId;
}