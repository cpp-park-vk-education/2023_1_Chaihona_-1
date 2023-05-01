#pragma once
class Lifestyle {
private:
    std::string name;
    std::string description;
    std::vector<std::string> variants;
    std::string userChoice;
public:
    Lifestyle();
    std::string getName() {return std::string("Zodiac sign");};
    std::string getDescription() {return std::string("What is your zodiac sign");};
    std::vector<std::string> getVariants();
    std::string getUserChoice() {return std::string{"Aquarius"};};        
};