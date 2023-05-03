#include "interest.hpp"


class InterestRequests {
private:
    unsigned userId;
    unsigned interestId;
    unsigned rate;
public:
    InsertInterest() {};
    unsigned insert() {};
    bool update() {};
    std::vector<Interest> getPossibleInterests () {};
}