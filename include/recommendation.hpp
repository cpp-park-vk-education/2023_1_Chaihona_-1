#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"
#include "filtering.hpp"

class Profile {};

class Recommendation {  
 private:
  Profile profile_;
  std::vector<Profile> recommended_profiles_;
 public:
  Recommendation() = delete;
  Recommendation(Profile& profile, const std::vector<Profile>& recommended_profiles) 
    : profile_(profile),
      recommended_profiles_(recommended_profiles) {}
  void vectorize_profile();
  void recommend();
};
