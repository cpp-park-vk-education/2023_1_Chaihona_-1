#pragma once

#include <string>
#include <vector>
#include <memory>

struct Profile
{
  std::string name;
  std::string email;
  /*...*/
};

struct User{
  User(std::string login_, std::string password_){
    login = login_;
    password = password_;
  }
  std::string login;
  std::string password;
  
  bool operator==(const User& user) const {
    if (user.login == login && user.password == password) return true;
    return false; 
  }
};

struct Form{
  unsigned id;

  bool operator==(const Form& form) const {
    return form.id == id;
  }
  /*some parametres*/
};

class IDatabaseManager {
public:
  virtual ~IDatabaseManager() {}
  virtual Profile authorise(User user) = 0;
  virtual std::vector<Profile> getRecomendations(Profile profile) = 0;
  virtual unsigned addUser(User user) = 0;
  virtual bool makeMatch(unsigned author_id, unsigned target_id) = 0; 
  virtual bool breakMatch(unsigned author_id, unsigned target_id) = 0;
  virtual Form getUserForm(unsigned) = 0; 
  virtual std::vector<Form> getRecommendForms(Form) = 0;
  virtual void editRecommendations(unsigned, std::vector<Profile>&) = 0;
  virtual void editUser(User user) = 0;
  virtual void editForm(Form Form) = 0;
};

class IRecommendation {
public:
  virtual void recommend() = 0;
  virtual void VectorizeProfileText() = 0;
};

// class DatabaseManager : public IDatabaseManager {
// public:
//   virtual Profile authorise(User user) override;
//   virtual std::vector<Profile> getRecomendations(Profile profile) override;
// };