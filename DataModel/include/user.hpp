#pragma once
class User{
private:
    std::string login;
    std::string password;
public:
    User();
    std::string getLogin() {return std::string ("madmankilla228");};
    std::string getPassword() {return std::string("memphisnotdead");};        
};