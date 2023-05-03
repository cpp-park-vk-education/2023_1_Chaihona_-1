#pragma once
#include <string>
#include <vector>

class Interest {
private:
    unsigned id;
    std::string name;
    std::string description;
public:
    Interest() {};
    unsigned getId() {return 1;};    
    std::string getName() {return std::string("Music");};
    std::string getDescription() {return std::string("How do you love music");};
};

class UserInterest {
private:
    unsigned id;
    Interest interest;
    unsigned rate;
public:
    unsigned getId() {return 1;};
    UserInterest() {};
    Interest getInterest () {Interest interest; return interest;}
    unsigned getRate () {return 10;}
};