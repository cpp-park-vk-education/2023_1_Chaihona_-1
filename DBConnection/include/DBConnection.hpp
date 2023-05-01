#pragma once

#ifndef _DBCONN_HPP_
#define _DBCONN_HPP_

#include <map>
#include <pqxx/pqxx>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <json.hpp>

using json = nlohmann::json;

class DBConnection {
private:
    std::map<std::string, std::string> config;
    pqxx::connection* connection;
    pqxx::work* cursor;
    pqxx::nontransaction* nontxn;
    bool transaction;
public:
    DBConnection();
    void enter(bool transact);
    void exit();
    ~DBConnection();
};

#endif