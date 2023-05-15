#pragma once
#include <string>
#include <boost/json.hpp>


namespace json = boost::json;

class User{
private:
    unsigned id;
    std::string login;
    std::string password;
public:
    User() {};
    User (std::string _lg, std::string _pass) : login(_lg), password(_pass), id(0) {}
    User (unsigned _id, std::string _lg, std::string _pass) : login(_lg), password(_pass), id(_id) {}
    unsigned getId() const {return 1;};
    const std::string getLogin() const {return login;}
    const std::string getPassword() const {return password;};       
};

void tag_invoke(const json::value_from_tag&, json::value& jv, User const& user);

User tag_invoke(json::value_to_tag<User>, json::value const& jv);


class Profile{
private:
    unsigned id;
    User user;
    std::string email;
    std::string firstName;
    std::string lastName;
public:
    Profile() {};  
    Profile (unsigned _id, User _user, std::string _mail, std::string _fn, std::string _ln) : id(_id), user(_user), email(_mail), firstName(_fn), lastName(_ln) {};
    Profile (std::string _mail, std::string _fn, std::string _ln) : email(_mail), firstName(_fn), lastName(_ln) {};
    unsigned getId() const {return id;};
    User getUser() const {return user;}
    void setUser(User usr) {user=usr;}
    std::string getEmail() const {return email;};
    std::string getFirstName() const {return firstName;};
    std::string getLastName() const {return lastName;};      
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Profile const& profile);

Profile tag_invoke(json::value_to_tag<Profile>, json::value const& jv);


class Interest {
private:
    unsigned id;
    std::string name;
    std::string description;
public:
    Interest() {}
    Interest(unsigned _id, std::string _name, std::string _descr) : id(_id), name(_name), description(_descr) {}
    unsigned getId() const {return id;};    
    std::string getName() const {return name;};
    std::string getDescription() const {return description;};
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Interest const& interest);

Interest tag_invoke(json::value_to_tag<Interest>, json::value const& jv);

class UserInterest {
private:
    unsigned uinterestId;
    unsigned user_id;
    Interest interest;
    unsigned rate;
public:
    unsigned getId() {return uinterestId;};
    unsigned getUserId() {return user_id;}
    UserInterest() {};
    UserInterest (unsigned _uid, Interest _int, unsigned _rate, unsigned _uiid) : user_id(_uid), interest(_int), rate(_rate), uinterestId(_uiid) {};
    Interest getInterest () const {return interest;}
    unsigned getRate () const {return rate;}
};

void tag_invoke(const boost::json::value_from_tag &, boost::json::value &jv, UserInterest const &interest);
UserInterest tag_invoke(boost::json::value_to_tag<UserInterest>, boost::json::value const& jv);

class Lifestyle {
private:
    unsigned id;
    std::string name;
    std::string description;
    std::vector<std::string> variants;
public:
    Lifestyle() {};
    Lifestyle (unsigned _id, std::string _name, std::string _descr, std::vector<std::string> _vars) : id(_id), name(_name), description(_descr), variants(_vars) {}
    std::string getName() const {return name;};
    std::string getDescription() const {return description;};
    std::vector<std::string> getVariants() const {return variants; };   
    unsigned getId() const {return id;}
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Lifestyle const& lifestyle);

Lifestyle tag_invoke(json::value_to_tag<Lifestyle>, json::value const& jv);

class UserLifestyle {
private:
    unsigned id;
    unsigned userId;
    Lifestyle lifestyle;
    std::string userChoice;
public:
    UserLifestyle() {};
    UserLifestyle(unsigned _uid, Lifestyle _lst, std::string _uchoice) : userId(_uid), lifestyle(_lst), userChoice(_uchoice) {}
    unsigned getUserId() const {return userId;};
    Lifestyle getLifestyle() const {return lifestyle;}
    std::string getUserChoice() const {return userChoice;};         
};


class Contact {
private: 
    unsigned user_id;
    unsigned id;
    std::string contactType;
    std::string value;
public:
    Contact() = default;
    Contact(unsigned _id, unsigned _uid, std::string _ct, std::string _val) : id(_id), user_id(_uid), contactType(_ct), value(_val) {}; 
    Contact(unsigned _uid, std::string _ct, std::string _val) : user_id(_uid), contactType(_ct), value(_val) {}; 
    unsigned getId() const {return 1;};
    std::string getContactType() const {return contactType;};
    std::string getContactValue() const {return value;};   
    unsigned getUserId() const {return user_id;}
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Contact const& contact);

Contact tag_invoke(json::value_to_tag<Contact>, json::value const& jv);


class Form{
private:
    Profile profile;
    unsigned id;
    std::vector<Interest> interests;
    std::vector<Lifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string university;
    std::string career;
    std::string location;
    time_t birthDate;
public:
    Form() {};    
    Form(unsigned _id, std::vector<Interest> _interests, std::vector<Lifestyle> _lifestyle, std::vector<Contact> _contact, 
        std::string _description, std::string _university, std::string _career, std::string _location) 
        : id(_id), interests(_interests), lifestyle(_lifestyle), contact(_contact), description(_description), 
        university(_university), career(_career), location(_location) {} 
    unsigned getId() const {return 1;};
    Profile getProfile() const {Profile profile; return profile;};
    std::vector<Interest> getInterests() const {std::vector<Interest> result; Interest interest; result.push_back(interest); return result;};
    std::vector<Lifestyle> getLifestyle() const {std::vector<Lifestyle> result; Lifestyle lifestyle; result.push_back(lifestyle); return result;};
    std::vector<Contact> getContacts() const {std::vector<Contact> result; Contact contact; result.push_back(contact); return result;}
    std::string getDescription() const {return std::string("Sample description");};
    std::string getUniversity() const {return std::string("BMSTU");};
    std::string getCareer() const {return std::string("Senior HTML Developer at VK");};
    std::string getLocation() const {return std::string("Russia, Saint-Petersburg, Krestovsky island");};
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Form const& profile);

Form tag_invoke(json::value_to_tag<Form>, json::value const& jv);

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, UserLifestyle const& lifestyle);
UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv);