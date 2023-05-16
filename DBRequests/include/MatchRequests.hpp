#pragma once
#include "match.hpp"
#include <string>
#include <vector>

class MatchRequests {
private:
    unsigned firstId;
    unsigned secondId;
    bool match;
public:
    MatchRequests() {};
    MatchRequests(unsigned _uid1) : firstId(_uid1) {}
    MatchRequests(unsigned _uid1, unsigned _uid2) : firstId(_uid1), secondId(_uid2) {}
    MatchRequests(unsigned _uid1, unsigned _uid2, bool _match) : firstId(_uid1), secondId(_uid2), match(_match) {}
    std::vector<unsigned> getUserMatches();
    bool matchResult();
    unsigned insert();
};