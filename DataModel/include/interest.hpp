#pragma once
class Interest {
private:
    std::string name;
    std::string description;
    unsigned rate;
public:
    Interest();    
    std::string getName() {return std::string("Music");};
    std::string getDescription() {return std::string("How do you love music");};
    unsigned getRate() {return 10;};
};