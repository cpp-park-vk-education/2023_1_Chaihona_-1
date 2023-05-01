#pragma once
#include "user.hpp"

enum MATCHTYPE {LIKE, DISLIKE};

class Match {
private:
    User user1;
    User user2;
    MATCHTYPE type;
public:
    Match(); 
    User getUser1();
    User getUser2();
    MATCHTYPE getType() {return MATCHTYPE::LIKE;};   
};