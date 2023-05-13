#include <format>
#include <string>
#include <vector>
#include <iostream>
#include "MatchRequests.hpp"

int main() {
    MatchRequests mReq(3, 1, 1);
    std::cout << mReq.insert();
}
