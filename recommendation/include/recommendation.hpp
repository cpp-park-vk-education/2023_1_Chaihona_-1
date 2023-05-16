#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"
#include "filtering.hpp"
#include "form.hpp" // <- файлик с Form

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
  void vectorize_profile();
  void recommend();
};