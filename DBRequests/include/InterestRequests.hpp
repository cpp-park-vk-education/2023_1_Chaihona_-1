#pragma once
#include "interest.hpp"
#include <string>
#include <vector>

class InterestRequests {
public:    
    InterestRequests() {}
    std::vector<Interest> getPossibleInterests();
};