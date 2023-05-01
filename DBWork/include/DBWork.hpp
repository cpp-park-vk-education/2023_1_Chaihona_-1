#include "DBConnection.hpp"
#include <string>
#include <utility>
#include <iostream>

class DBWork{
private:
    DBConnection* dbConnection;
public:
    DBWork(DBConnection* _conn) : dbConnection(_conn) {}
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> select (std::string sql);
    void update (std::string sql);
    int insert (std::string sql);    
    ~DBWork() {delete dbConnection;}
};