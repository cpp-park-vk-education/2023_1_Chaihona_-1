#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"
#include "filtering.hpp"
#include "form.hpp"
#include "interest.hpp"

class Recommendation {  
 private:
  Form form_;
  UserForm user_;
  std::vector<Form> recommended_forms_;
  std::vector<UserForm> recommended_users_;
  static const std::string DOCS_FILE;

  void forms_to_users();
  void users_to_forms();

 public:
  Recommendation() = delete;
  Recommendation(Form& form, const std::vector<Form>& recommended_forms) 
    : form_(form),
      recommended_forms_(recommended_forms) {}
  void recommend();
  void vectorize_profile_text();
  Form get_form() { return form_; }
  std::vector<Form> get_recommended_forms() { return recommended_forms_; }
};
