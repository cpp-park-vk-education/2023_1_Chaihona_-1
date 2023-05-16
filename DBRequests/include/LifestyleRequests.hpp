#pragma once
#include "lifestyle.hpp"
#include <string>
#include <vector>

class LifestyleRequests {
public:   
    LifestyleRequests() {}
    std::vector<Lifestyle> getPossibleLifestyles();
};

std::vector<std::string> splitDbArray (std::string dbArray);