#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "text_processing.hpp"

#define STOPWORDS_FILENAME "stopwords_ru.txt"
#define DOCUMENTS_FILENAME "documents.txt"

class IVectorizer {
 private: 
 public:
   virtual void vectorize(ITokenizer& tokenizer, IStemmer& stemmer) = 0;
   virtual std::vector<double> get_vect() = 0;
};

class VectorizerTFIDF : public IVectorizer {
 private:
  std::string text_;
  std::vector<double> vect_;
  std::string stopwords_filename_;
  std::string documents_filename_;
  double tf_;
  double idf_;

  double calculate_TF(const std::string& word, const std::string& text);
  double calculate_IDF(std::string word, const std::string& filename);
  void tokenize_text(ITokenizer& tokenizer);
  void stemmize_text(IStemmer& stemmer);

 public:
  VectorizerTFIDF() = default;
  explicit VectorizerTFIDF(const std::string& text) 
    : text_(text),
      stopwords_filename_(STOPWORDS_FILENAME),
      documents_filename_(DOCUMENTS_FILENAME) {}

  
  void vectorize(ITokenizer& tokenizer, IStemmer& stemmer);
  void set_text(const std::string& text);
  void set_filename(const std::string& filename);
  std::vector<double> get_vect();
  double get_tf(const std::string& word);
  double get_idf(const std::string& word);
};
