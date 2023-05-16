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
    UserInterest (Interest _int, unsigned _rate) :  interest(_int), rate(_rate) {}
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
    Contact( std::string _ct, std::string _val) :  contactType(_ct), value(_val) {}; 
    unsigned getId() const {return 1;};
    std::string getContactType() const {return contactType;};
    std::string getContactValue() const {return value;};   
    unsigned getUserId() const {return user_id;}
};

void tag_invoke(const json::value_from_tag&, json::value& jv, Contact const& contact);

Contact tag_invoke(json::value_to_tag<Contact>, json::value const& jv);


class Preference {
private:
    unsigned minAge;
    unsigned maxAge;
    unsigned radius;
    char gender; //F for female, M for male
public:
    Preference() {}
    Preference(unsigned _mina, unsigned _maxa, unsigned _rad, char _gender) : minAge(_mina), maxAge(_maxa), radius(_rad), gender(_gender) {}
    unsigned getMinAge() const {return minAge;}
    unsigned getMaxAge() const {return maxAge;}
    unsigned getRadius() const {return radius;}
    char getGender() const {return gender;}
};


class Form{
private:
    Profile profile;
    unsigned id;
    Preference preference;
    std::vector<UserInterest> interests;
    std::vector<UserLifestyle> lifestyle;
    std::vector<Contact> contact;
    std::string description;
    std::string preworkedText;
    std::vector<double> vectorisedText;
    std::string university;
    std::string career;
    std::string location;
    std::string bdate;
    char gender;
    unsigned age;
public:
    Form() {};
    Form(unsigned _id, std::vector<UserInterest> _iv, std::vector<UserLifestyle> _lv, std::string _desc, std::string _un, std::string _carr, std::string _loc, unsigned _age) : id(_id), lifestyle(_lv), interests(_iv), description(_desc), university(_un), career(_carr), location(_loc), age(_age) {}     
    Form(unsigned _id, std::vector<UserInterest> _iv, std::vector<UserLifestyle> _lv, std::string _desc, std::string _un, std::string _carr, std::string _loc, unsigned _age, char _gend, std::string _bday, Preference _pref) : age(_age), id(_id), lifestyle(_lv), interests(_iv), description(_desc), university(_un), career(_carr), location(_loc), gender(_gend), bdate(_bday), preference(_pref) {}   
    unsigned getId() const {return id;};
    Profile getProfile() {Profile profile; return profile;};
    std::vector<UserInterest> getInterests() const {return interests;};
    std::vector<UserLifestyle> getLifestyle() const {return lifestyle;};
    std::string getDescription() const {return description;};
    std::string getUniversity() const {return university;};
    std::string getCareer() const {return career;};
    std::string getLocation() const {return location;};
    unsigned getAge() const {return age;}
    std::string getBdate() const {return bdate;}
    char getGender() const {return gender;}
    Preference getPreference() const {return preference;}
};

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Form const& form);
Form tag_invoke(boost::json::value_to_tag<Form>, boost::json::value const& jv);

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, Preference const& user);
Preference tag_invoke(boost::json::value_to_tag<Preference>, boost::json::value const& jv);

void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, UserLifestyle const& lifestyle);
UserLifestyle tag_invoke(boost::json::value_to_tag<UserLifestyle>, boost::json::value const& jv);