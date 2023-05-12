#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"

class Profile {};

class SimilarityCalculator {
 private:
 public:
  virtual void set_vectors(std::vector<double>& first, std::vector<double>& second) = 0;
  virtual void calculate() = 0;
  virtual double get_similarity() = 0;
};

class CosSimilarityCalculator : public SimilarityCalculator {
 private:
  std::vector<double> first_;
  std::vector<double> second_;
  double cos_similarity_;

 public:
  CosSimilarityCalculator() = default;
  CosSimilarityCalculator(std::vector<double>& first, std::vector<double>& second) :
    first_(first),
    second_(second) {}

  void set_vectors(std::vector<double>& first, std::vector<double>& second);
  void calculate();
  double get_similarity();
};

struct User {
 public:
  User() = default;
  explicit User(const Profile& profile); // реализуй
  size_t id_;
  std::vector<double> text_vect_;
  std::vector<double> interest_vect_;
  double interest_similarity_;
  double text_similarity_;
  double similarity_;
  bool operator< (const User& p) const {
    return this->similarity_ < p.similarity_;
  }
};

class Filter {
 private:
  User user_;
  std::vector<User> recommended_users_;

 public:
  Filter() = delete;
  Filter(User& user, std::vector<User>& recommended_users)
    : user_(user), 
      recommended_users_(recommended_users) {}
  void calculate_users_similiarity(SimilarityCalculator& sim_calculator);
  std::vector<User> get_recommended_users();
};
