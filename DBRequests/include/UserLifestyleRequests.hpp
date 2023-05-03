#include "lifestyle.hpp"


class LifestyleRequests {
private:
    unsigned userId;
    unsigned lifestyleId;
    std::string userChoice;
public:
    LifestyleRequests() {};
    unsigned insert() {}; 
    bool update() {}; 
    std::vector<Lifestyle> getPossibleLifestyles() {};   
};