#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "text_processing.hpp"

class VectorizerTFIDF {
 private:
  std::string text_;
  std::vector<std::string> tokens_;
  std::vector<double> vect_;
  std::vector<std::string> documents_;

  double calculate_TF(const std::string& word);
  double calculate_IDF(std::string word);
  void processing_text(ITokenizer& tokenizer, IStemmer& stemmer);

 public:
    VectorizerTFIDF() = delete;
    explicit VectorizerTFIDF(std::istream& docs) 
    : text_(text) {
        set_documents(docs);
      }

  void vectorize(ITokenizer& tokenizer, IStemmer& stemmer);
  void set_text(const std::string& text);
  // void set_documents(std::istream& docs);
  std::vector<double> get_vect();
};
