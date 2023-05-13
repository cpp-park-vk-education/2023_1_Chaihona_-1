#pragma once
#include <string>
#include <vector>

class Interest {
private:
    unsigned id;
    std::string name;
    std::string description;
public:
    Interest() {}
    Interest(unsigned _id, std::string _name, std::string _descr) : id(_id), name(_name), description(_descr) {};
    unsigned getId() {return id;};    
    std::string getName() {return name;};
    std::string getDescription() {return description;};
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
    Interest getInterest () {return interest;}
    unsigned getRate () {return rate;}
};