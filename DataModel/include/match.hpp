#pragma once
#include "user.hpp"
#include <string>
#include <vector>

enum MATCHTYPE {LIKE, DISLIKE};

class Match {
private:
    unsigned id;
    User user1;
    User user2;
    MATCHTYPE type;
public:
    Match() {}; 
    unsigned getId() {return 1;};
    User getUser1(){ User user; return user; };
    User getUser2() { User user; return user; };
    MATCHTYPE getType() {return MATCHTYPE::LIKE;};   
};