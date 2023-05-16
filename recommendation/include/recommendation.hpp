#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"
#include "filtering.hpp"
// #include "" // <- файлик с Form и UserInterest

#define DOCS_FILE "...txt"

class UserInterest {
private:
    unsigned uinterestId;
    // unsigned user_id;
    // Interest interest;
    unsigned rate;
public:
    unsigned getId() {return uinterestId;};
    // unsigned getUserId() {return user_id;}
    UserInterest() {};
    // UserInterest (unsigned _uid, Interest _int, unsigned _rate, unsigned _uiid) : user_id(_uid), interest(_int), rate(_rate), uinterestId(_uiid) {};
    // Interest getInterest () {return interest;}
    unsigned getRate () {return rate;}
};

class Form{
private:
    // Profile profile;
    unsigned id;
    std::vector<UserInterest> interests;
    // std::vector<UserLifestyle> lifestyle;
    // std::vector<Contact> contact;
    std::string description;
    std::string preworkedText;
    std::vector<double> vectorisedText;
    // std::string university;
    // std::string career;
    // std::string location;
    // unsigned age;
public:
    Form() {};    
    unsigned getId() {return 1;};
    std::vector<UserInterest> getInterests() {
      return interests;
    }
    std::string getDescription() {
      return preworkedText;
    }
    std::vector<double> getVectorisedText() {
      return vectorisedText;
    }
    // Profile getProfile() {Profile profile; return profile;};
    // std::vector<Lifestyle> getLifestyle() {std::vector<Lifestyle> result; Lifestyle lifestyle; result.push_back(lifestyle); return result;};
    //  std::vector<Contact> getContacts() {std::vector<Contact> result; Contact contact; result.push_back(contact); return result;}
    // std::string getUniversity() {return std::string("BMSTU");};
    // std::string getCareer() {return std::string("Senior HTML Developer at VK");};
    // std::string getLocation() {return std::string("Russia, Saint-Petersburg, Krestovsky island");};
};

class Recommendation {  
 private:
  Form form_;
  UserForm user_;
  std::vector<Form> recommended_forms_;
  std::vector<UserForm> recommended_users_;
  void forms_to_users();
  void users_to_forms();

 public:
  Recommendation() = delete;
  Recommendation(Form& form, const std::vector<Form>& recommended_forms) 
    : form_(form),
      recommended_forms_(recommended_forms) {}
  void recommend();
  void vectorize_profile_text();
  Form get_form() {
    return form_;
  }
  std::vector<Form> get_recommended_forms() {
    return recommended_forms_;
  }
};
