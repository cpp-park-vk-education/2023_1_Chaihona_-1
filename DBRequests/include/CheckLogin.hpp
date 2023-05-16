#pragma once
#include <string>
#include <vector>

class CheckLogin {
private:
    std::string login;
public:
    CheckLogin(std::string _login) : login(_login) {};
    bool exec();        
};