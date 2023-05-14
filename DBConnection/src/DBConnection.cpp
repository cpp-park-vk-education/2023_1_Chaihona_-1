#include "DBConnection.hpp"
#include <format>

DBConnection::DBConnection() {
    std::ifstream f("../configs/db.json");
    json data = json::parse(f);
    config["host"] = data["host"];
    config["user"] = data["user"];
    config["password"] = data["password"];
    config["database"] = data["database"];
    config["port"] = data["port"];
}


void DBConnection::enter(bool transact) {
    try {
        std::string connConfig = std::format("dbname={} user={} password={} \
                                            host={} port={}", config["database"], \
                                            config["user"], config["password"], config["host"], config["port"]);
        connection = new pqxx::connection(connConfig);
        if (transact) {
            cursor = new pqxx::work(*connection);
            transaction = true;
        } else {
            nontxn = new pqxx::nontransaction(*connection);
            transaction = false;
        }
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void DBConnection::exit() {
    if (connection) {
        if (transaction)
            cursor->commit();
        connection->disconnect();
        //connection->close();    
    }
}

DBConnection::~DBConnection() {
    delete connection;
    if (transaction)
        delete cursor;
    else
        delete nontxn;    
}
