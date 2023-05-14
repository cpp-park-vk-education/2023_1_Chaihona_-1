#pragma once
#include "user.hpp"
#include <string>
#include <vector>

class Profile{
private:
    unsigned id;
    User user;
    std::string email;
    std::string firstName;
    std::string lastName;
public:
    Profile() {};  
    Profile (std::string _mail, std::string _fn, std::string _ln) : email(_mail), firstName(_fn), lastName(_ln) {};
    unsigned getId() {return id;};
    User getUser() {return user;}
    void setUser(User usr) {user=usr;}
    std::string getEmail() const {return email;};
    std::string getFirstName() const {return firstName;};
    std::string getLastName() const {return lastName;};      
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Profile const& profile);
Profile tag_invoke(boost::json::value_to_tag<Profile>, boost::json::value const& jv);