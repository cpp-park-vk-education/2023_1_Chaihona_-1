#pragma once
#include <string>
#include <vector>
#include <boost/json.hpp>

class Lifestyle {
private:
    unsigned id;
    std::string name;
    std::string description;
    std::vector<std::string> variants;
public:
    Lifestyle() {};
    Lifestyle (unsigned _id, std::string _name, std::string _descr, std::vector<std::string> _vars) : id(_id), name(_name), description(_descr), variants(_vars) {}
    std::string getName() const {return name;};
    std::string getDescription() const {return description;};
    std::vector<std::string> getVariants() const {return variants; };   
    unsigned getId() const {return id;}
};

class UserLifestyle {
private:
    unsigned id;
    unsigned userId;
    Lifestyle lifestyle;
    std::string userChoice;
public:
    UserLifestyle() {};
    UserLifestyle(unsigned _uid, Lifestyle _lst, std::string _uchoice) : userId(_uid), lifestyle(_lst), userChoice(_uchoice) {}
    unsigned getUserId() {return userId;};
    Lifestyle getLifestyle() const {return lifestyle;}
    std::string getUserChoice() const {return userChoice;};         
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Lifestyle const& lifestyle);
Lifestyle tag_invoke(boost::json::value_to_tag<Lifestyle>, boost::json::value const& jv);

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, UserLifestyle const& lifestyle);
UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv);