#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

class ITokenizer {
 private:
 public:
    virtual void tokenize() = 0;
    virtual std::vector<std::string> get_tokens() = 0;
};

class IStemmer {
 private:
 public:
    virtual void stemmize() = 0;
    virtual std::vector<std::string> get_stems() = 0;
};

class CleanTokenizer : public ITokenizer {
 private:
    std::string text_;
    std::vector<std::string> tokens_;
    std::vector<std::string> stop_words_;

    void text_split();
    void delete_punctuation();
    void to_lower();
    bool is_stop_word(std::string word);
    void delete_stopwords();

 public:
    CleanTokenizer() = default;
    explicit CleanTokenizer(const std::string& text, std::vector<std::string>& stop_words) : 
      text_(text), 
      stop_words_(stop_words) {}

    void set_text(const std::string& text);
    void tokenize();
    std::string get_text();
    std::vector<std::string> get_tokens();
};

class PortersStemmer : public IStemmer {
 private:
    std::vector<std::string> tokens_;
 
 public:
    PortersStemmer() = default;
    explicit PortersStemmer(const std::vector<std::string>& tokens) : tokens_(tokens) {}
   
    void set_tokens(const std::vector<std::string>& tokens_vect);
    void stemmize();
    std::vector<std::string> get_tokens();
    std::vector<std::string> get_stems();
};
