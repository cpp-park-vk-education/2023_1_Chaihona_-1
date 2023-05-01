#include "DBWork.hpp"

std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> DBWork::select(std::string sql) {
    dbConnection->enter(true); 
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> output;
    dbConnection->exit(); 
    return output;
}

void DBWork::update(std::string sql) {
    dbConnection->enter(true); 
    dbConnection->exit(); 
}

int DBWork::insert(std::string sql) {
    dbConnection->enter(true);
    int newObjId = 1; 
    dbConnection->exit(); 
    return newObjId;
}