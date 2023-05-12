#include "text_processing.hpp"


void CleanTokenizer::text_split() {
    std::string tmp_str;
    std::stringstream str_stream(text_);

    while (str_stream) {
        getline(str_stream, tmp_str, ' ');
        tokens_.push_back(tmp_str);
    }
    tokens_.pop_back();
}

void CleanTokenizer::delete_punctuation() {
    for (std::string& token : tokens_) {
        for (int i = 0; i < token.length(); i++) {
            if (ispunct(token[i])) {
                token.erase(i--, 1);
            }
        }
    }
}

void CleanTokenizer::to_lower() {
    // реализуй
}

void CleanTokenizer::delete_stopwords() {
    for (std::string token : tokens_) {
        if (is_stop_word(token)) {
            tokens_.erase(std::find(tokens_.begin(), tokens_.end(), token));
        }
    }
}

bool CleanTokenizer::is_stop_word(std::string word) {
    for (auto stop_word : stop_words_) {
        if (word == stop_word) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> CleanTokenizer::get_tokens() {
    return tokens_;
}

void CleanTokenizer::tokenize() {
    text_split();
    delete_punctuation();
    to_lower();
    delete_stopwords();
}