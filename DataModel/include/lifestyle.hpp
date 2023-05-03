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
    std::string getName() {return std::string("Zodiac sign");};
    std::string getDescription() {return std::string("What is your zodiac sign");};
    std::vector<std::string> getVariants() {std::vector<std::string>variants; variants.push_back("Aquarius"); return variants; };   
};

class UserLifestyle {
private:
    unsigned id;
    Lifestyle lifestyle;
    std::string userChoice;
public:
    UserLifestyle() {};
    unsigned getId() {return 1;};
    Lifestyle getLifestyle() {Lifestyle lifestyle; return lifestyle;}
    std::string getUserChoice() {return std::string{"Aquarius"};};         
};