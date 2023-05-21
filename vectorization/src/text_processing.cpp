#include "text_processing.hpp"

const std::wstring PortersStemmer::const1 = L"АЕИОУЫЭИЮЯ";
const std::wstring PortersStemmer::EMPTY = L"";
const std::wstring PortersStemmer::S1 = L"$1";
const std::wstring PortersStemmer::S13 = L"$1$3";
const std::wstring PortersStemmer::SN = L"Н";

const std::wregex PortersStemmer::PERFECTIVEGROUND = std::wregex(L"(ИВ|ИВШИ|ИВШИСЬ|ЫВ|ЫВШИ|ЫВШИСЬ|ВШИ|ВШИСЬ)$");
const std::wregex PortersStemmer::REFLEXIVE = std::wregex(L"(СЯ|СЬ)$");
const std::wregex PortersStemmer::ADJECTIVE = std::wregex(L"(ЕЕ|ИЕ|ЫЕ|ОЕ|ИМИ|ЫМИ|ЕЙ|ИЙ|ЫЙ|ОЙ|ЕМ|ИМ|ЫМ|ОМ|ЕГО|ОГО|ЕМУ|ОМУ|ИХ|ЫХ|УЮ|ЮЮ|АЯ|ЯЯ|ОЮ|ЕЮ)$");
const std::wregex PortersStemmer::PARTICIPLE = std::wregex(L"(.*)(ИВШ|ЫВШ|УЮЩ)$|([АЯ])(ЕМ|НН|ВШ|ЮЩ|Щ)$");
const std::wregex PortersStemmer::VERB = std::wregex(L"(.*)(ИЛА|ЫЛА|ЕНА|ЕЙТЕ|УЙТЕ|ИТЕ|ИЛИ|ЫЛИ|ЕЙ|УЙ|ИЛ|ЫЛ|ИМ|ЫМ|ЕН|ИЛО|ЫЛО|ЕНО|ЯТ|УЕТ|УЮТ|ИТ|ЫТ|ЕНЫ|ИТЬ|ЫТЬ|ИШЬ|УЮ|Ю)$|([АЯ])(ЛА|НА|ЕТЕ|ЙТЕ|ЛИ|Й|Л|ЕМ|Н|ЛО|НО|ЕТ|ЮТ|НЫ|ТЬ|ЕШЬ|ННО)$");
const std::wregex PortersStemmer::NOUN = std::wregex(L"(А|ЕВ|ОВ|ИЕ|ЬЕ|Е|ИЯМИ|ЯМИ|АМИ|ЕИ|ИИ|И|ИЕЙ|ЕЙ|ОЙ|ИЙ|Й|ИЯМ|ЯМ|ИЕМ|ЕМ|АМ|ОМ|О|У|АХ|ИЯХ|ЯХ|Ы|Ь|ИЮ|ЬЮ|Ю|ИЯ|ЬЯ|Я)$");
const std::wregex PortersStemmer::I = std::wregex(L"И$");
const std::wregex PortersStemmer::P = std::wregex(L"Ь$");
const std::wregex PortersStemmer::NN = std::wregex(L"НН$");
const std::wregex PortersStemmer::DERIVATIONAL = std::wregex(L".*[^АЕИОУЫЭЮЯ]+[АЕИОУЫЭЮЯ].*ОСТЬ?$");
const std::wregex PortersStemmer::DER = std::wregex(L"ОСТЬ?$");
const std::wregex PortersStemmer::SUPERLATIVE = std::wregex(L"(ЕЙШЕ|ЕЙШ)$");
const std::wregex PortersStemmer::PUNCTUATION = std::wregex(L"[^\\w\\s]$");

const std::string CleanTokenizer::STOPWORDS_FILENAME = "stopwords_ru.txt";

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
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring s;
    for (std::string& str : tokens_) {
        s = converter.from_bytes(str);
        std::transform(s.begin(), s.end(), s.begin(), std::towlower);
        str = converter.to_bytes(s);
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

void CleanTokenizer::delete_stopwords() {
    for (std::string token : tokens_) {
        if (is_stop_word(token)) {
            tokens_.erase(std::find(tokens_.begin(), tokens_.end(), token));
        }
    }
}

std::vector<std::string> CleanTokenizer::get_tokens() {
    return tokens_;
}

void CleanTokenizer::tokenize() {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");
    text_split();
    delete_punctuation();
    to_lower();
    delete_stopwords();
}

void CleanTokenizer::set_text(const std::string& text) {
    tokens_.clear();
    text_ = text;
}


void PortersStemmer::stemmize() {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring s;
    for (std::string& str : tokens_) {
        s = converter.from_bytes(str);
        std::transform(s.begin(), s.end(), s.begin(), std::towupper);
        std::replace(s.begin(), s.end(), L'Ё', L'Е');

        size_t pos = s.find_first_of(const1, 0);

        if (pos != std::wstring::npos) {
            std::wstring pre = s.substr(0, pos + 1);
            std::wstring rv = s.substr(pos + 1);
            std::wstring temp = std::regex_replace(rv, PERFECTIVEGROUND, EMPTY);

            if (rv.size() != temp.size()) {
                rv = temp;
            } else {
                rv = std::regex_replace(rv, REFLEXIVE, EMPTY);
                temp = std::regex_replace(rv, ADJECTIVE, EMPTY);

                if (rv.size() != temp.size()) {
                    rv = temp;
                    rv = regex_replace(rv, PARTICIPLE, S13);
                } else {
                    temp = regex_replace(rv, VERB, S13);
                    if (rv.size() != temp.size()) {
                        rv = temp;
                    } else {
                        rv = regex_replace(temp, NOUN, EMPTY);
                    }
                }
            }

            rv = regex_replace(rv, I, EMPTY);

            if (regex_match(rv, DERIVATIONAL)) {
                rv = regex_replace(rv, DER, EMPTY);
            }

            temp = regex_replace(rv, P, EMPTY);

            if (temp.length() != rv.length()) {
                rv = temp;
            } else {
                rv = regex_replace(rv, SUPERLATIVE, EMPTY);
                rv = regex_replace(rv, NN, SN);
            }
            s = pre + rv;
        }

        std::transform(s.begin(), s.end(), s.begin(), std::towlower);
        str = converter.to_bytes(s);
    }
    
}

std::vector<std::string> PortersStemmer::get_stems() {
    return tokens_;
}

void PortersStemmer::set_tokens(const std::vector<std::string>& tokens_vect) {
    tokens_.clear();
    tokens_ = tokens_vect;
}
