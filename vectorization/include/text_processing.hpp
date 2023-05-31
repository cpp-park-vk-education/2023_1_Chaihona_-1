#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <regex>
#include <iterator>
#include <functional>
#include <clocale>
#include <locale>  
#include <codecvt>

class ITokenizer {
 public:
    virtual ~ITokenizer() {};
    virtual void tokenize() = 0;
    virtual void set_text(const std::string& text) = 0;
    virtual std::vector<std::string> get_tokens() = 0;
};

class CleanTokenizer : public ITokenizer {
 private:
    std::string text_;
    std::vector<std::string> tokens_;
    std::vector<std::string> stop_words_;
    std::string stopwords_filename_;
    static const std::string STOPWORDS_FILENAME;

    void text_split();
    void delete_punctuation();
    void to_lower();
    bool is_stop_word(std::string word);
    void delete_stopwords();

 public:
    CleanTokenizer() : stopwords_filename_(STOPWORDS_FILENAME) {}
    CleanTokenizer(const std::string& text) : 
      text_(text), 
      stopwords_filename_(STOPWORDS_FILENAME) {}

    void set_text(const std::string& text) override;
    void tokenize() override;
    std::vector<std::string> get_tokens() override;
};

class IStemmer {
 public:
    virtual ~IStemmer() {};
    virtual void set_tokens(const std::vector<std::string>& tokens_vect) = 0;
    virtual void stemmize() = 0;
    virtual std::vector<std::string> get_stems() = 0;
};

class PortersStemmer : public IStemmer {
 private:
   std::vector<std::string> tokens_;
   static const std::wstring EMPTY;
	static const std::wstring S1;
	static const std::wstring S13;
	static const std::wstring SN;
	static const std::wstring const1;
	static const std::wregex PERFECTIVEGROUND;
	static const std::wregex REFLEXIVE;
	static const std::wregex ADJECTIVE;
	static const std::wregex PARTICIPLE;
	static const std::wregex VERB;
	static const std::wregex NOUN;
	static const std::wregex I;
	static const std::wregex P;
	static const std::wregex NN;
	static const std::wregex DERIVATIONAL;
	static const std::wregex DER;
	static const std::wregex SUPERLATIVE;
	static const std::wregex PUNCTUATION;
 
 public:
   PortersStemmer() {
      setlocale(LC_CTYPE, "ru_RU.UTF-8");
   }
   explicit PortersStemmer(const std::vector<std::string>& tokens) : tokens_(tokens) {
      setlocale(LC_CTYPE, "ru_RU.UTF-8");
   }
   
   void set_tokens(const std::vector<std::string>& tokens_vect);
   void stemmize();
   std::vector<std::string> get_stems();
};
