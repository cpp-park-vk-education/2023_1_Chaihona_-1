#pragma once
#include "lifestyle.hpp"
#include <string>
#include <vector>

class LifestyleRequests {
public:   
    LifestyleRequests() {}
    std::vector<Lifestyle> getPossibleLifestyles();
};