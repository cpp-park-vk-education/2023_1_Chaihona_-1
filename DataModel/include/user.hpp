#pragma once
class User{
private:
    unsigned id;
    std::string login;
    std::string password;
public:
    User() {};
    unsigned getId() {return 1;};
    std::string getLogin() {return std::string ("madmankilla228");};
    std::string getPassword() {return std::string("memphisnotdead");};        
};