#pragma once
#include <string>
#include <vector>
#include <boost/json.hpp>


class User{
private:
    unsigned id;
    std::string login;
    std::string password;
public:
    User() {};
    User (std::string _lg, std::string _pass) : login(_lg), password(_pass) {}
    unsigned getId() {return 1;};
    const std::string getLogin() const {return login;}
    const std::string getPassword() const {return password;};       
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, User const& user);
User tag_invoke(boost::json::value_to_tag<User>, boost::json::value const& jv);
