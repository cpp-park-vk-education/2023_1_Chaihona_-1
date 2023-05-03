#pragma once

class InsertProfile{
private:
    std::string email;
    std::string firstName;
    std::string lastName;
    unsigned userId;
public:
    InsertProfile() {};  
    unsigned exec() {};
};