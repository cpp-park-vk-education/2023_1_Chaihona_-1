#pragma once
#include <string>
#include <vector>

class CheckEmail {
private:
    std::string email;
public:
    CheckEmail(std::string _email) : email(_email) {};
    bool exec();        
};