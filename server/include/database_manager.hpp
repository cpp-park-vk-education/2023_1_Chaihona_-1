#pragma once

#include <string>
#include <vector>
#include <memory>
#include "user.hpp"
#include "profile.hpp"
// struct Profile
// {
//   std::string name;
//   std::string email;
//   /*...*/
// };

// struct User{
//   User(std::string login_, std::string password_){
//     login = login_;
//     password = password_;
//   }
//   std::string login;
//   std::string password;
  
//   bool operator==(const User& user) const {
//     if (user.login == login && user.password == password) return true;
//     return false; 
//   }
// };


// class IDatabaseManager {
// public:
//   virtual ~IDatabaseManager() {}
//   virtual Profile authorise(User user) = 0;
//   virtual std::vector<Profile> getRecomendations(Profile profile) = 0;
//   virtual unsigned addUser(User user) = 0;
//   virtual bool makeMatch(unsigned author_id, unsigned target_id) = 0; 
//   virtual bool breakMatch(unsigned author_id, unsigned target_id) = 0;
//   virtual Form getUserForm(unsigned) = 0; 
//   virtual std::vector<Form> getRecommendForms(Form) = 0;
//   virtual void editRecommendations(unsigned, std::vector<Profile>&) = 0;
//   virtual void editUser(User user) = 0;
//   virtual void editForm(Form Form) = 0;
//   virtual bool CheckIfEmailBusy(std::string) = 0;
//   virtual Form getRecommendForm(unsigned) = 0;
//   virtual bool getMatchResult(unsigned, unsigned) = 0;
// };

// class DatabaseManager : public IDatabaseManager {
// public:
//   virtual Profile authorise(User user) override {return Profile();}
//   virtual std::vector<Profile> getRecomendations(Profile profile) override {return std::vector<Profile>();}
//   virtual unsigned addUser(User user) override {return 0;}
//   virtual bool makeMatch(unsigned author_id, unsigned target_id) override {return true;}
//   virtual bool breakMatch(unsigned author_id, unsigned target_id) override {return false;}
//   virtual Form getUserForm(unsigned) override {return Form{};}
//   virtual std::vector<Form> getRecommendForms(Form) override {return std::vector<Form>();}
//   virtual Form getRecommendForm(unsigned) override {return Form();}
//   virtual void editRecommendations(unsigned, std::vector<Profile>&) override {}
//   virtual void editUser(User user) override {}
//   virtual void editForm(Form Form) override {}
//   virtual bool CheckIfEmailBusy(std::string) override {return true;}
//   virtual bool getMatchResult(unsigned, unsigned) override {return true;}
// };

