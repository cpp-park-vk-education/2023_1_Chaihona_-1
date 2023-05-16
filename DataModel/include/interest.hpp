#pragma once
#include <string>
#include <vector>
#include <boost/json.hpp>


class Interest {
private:
    unsigned id;
    std::string name;
    std::string description;
public:
    Interest() {}
    Interest(unsigned _id, std::string _name, std::string _descr) : id(_id), name(_name), description(_descr) {};
    unsigned getId() const {return id;};    
    std::string getName() const {return name;};
    std::string getDescription() const {return description;};
};

class UserInterest {
private:
    unsigned uinterestId;
    unsigned user_id;
    Interest interest;
    unsigned rate;
public:
    unsigned getId() {return uinterestId;};
    unsigned getUserId() {return user_id;}
    UserInterest() {};
    UserInterest (unsigned _uid, Interest _int, unsigned _rate, unsigned _uiid) : user_id(_uid), interest(_int), rate(_rate), uinterestId(_uiid) {};
    UserInterest (Interest _int, unsigned _rate) :  interest(_int), rate(_rate) {}
    Interest getInterest () const {return interest;}
    unsigned getRate () const {return rate;}
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Interest const& profile);
Interest tag_invoke(boost::json::value_to_tag<Interest>, boost::json::value const& jv);

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, UserInterest const& profile);
UserInterest tag_invoke(boost::json::value_to_tag<UserInterest>, boost::json::value const& jv);