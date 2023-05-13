#include "tfidf_vectorization.hpp"

void VectorizerTFIDF::processing_text(ITokenizer& tokenizer, IStemmer& stemmer) {
    tokenizer.set_text(text_);
    tokenizer.tokenize();

    stemmer.set_tokens(tokenizer.get_tokens());
    stemmer.stemmize();
    tokens_ = stemmer.get_stems();
}

double VectorizerTFIDF::calculate_TF(const std::string& word) {
    size_t count = 0;
    for (std::string w : tokens_) {
        if (word == w) {
            ++count;
        }   
    }
    double tf = count / tokens_.size();
    return tf;
}

void str_split(std::string& str, char sep, std::vector <std::string>& str_vect) {
    std::string tmp_str;
    std::stringstream str_stream(str);

    while (str_stream) {
        getline(str_stream, tmp_str, sep);
        str_vect.push_back(tmp_str);
    }   
    str_vect.pop_back();
}

double VectorizerTFIDF::calculate_IDF(std::string word) {
    std::vector<std::string> vec;
    size_t count = 0;
    for (std::string& document : documents_) {
        str_split(document, ' ', vec);
        bool found = std::find(vec.begin(), vec.end(), word) != vec.end();
        if (found) {
            ++count;
        }
        vec.clear();
    }

    return count / documents_.size();
}

void VectorizerTFIDF::set_documents(std::istream& docs) {
    std::string str_input;
    char sep = '\n';
    while (docs) {
        getline(docs, str_input, sep);
        str_split(str_input, ' ', documents_);
    }
    
}

void VectorizerTFIDF::vectorize(ITokenizer& tokenizer, IStemmer& stemmer) {
    processing_text(tokenizer,stemmer);
    double tf, idf;
    for (std::string str : tokens_) {
        tf = calculate_TF(str);
        idf = calculate_IDF(str);
        vect_.push_back(tf * idf);
    }
}

void VectorizerTFIDF::set_text(const std::string& text) {
    vect_.clear();
    tokens_.clear();
    text_ = text;
}
