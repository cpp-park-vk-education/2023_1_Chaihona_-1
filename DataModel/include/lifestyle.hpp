#pragma once
#include <string>
#include <vector>

class Lifestyle {
private:
    unsigned id;
    std::string name;
    std::string description;
    std::vector<std::string> variants;
public:
    Lifestyle() {};
    Lifestyle (unsigned _id, std::string _name, std::string _descr, std::vector<std::string> _vars) : id(_id), name(_name), description(_descr), variants(_vars) {}
    std::string getName() {return name;};
    std::string getDescription() {return description;};
    std::vector<std::string> getVariants() {return variants; };   
    unsigned getId() {return id;}
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
    Lifestyle getLifestyle() {return lifestyle;}
    std::string getUserChoice() {return userChoice;};         
};