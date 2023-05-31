#include <gtest/gtest.h>
#include "text_processing.hpp"

TEST(PortersStemmerTest, StemmizeTest1) {
    PortersStemmer stemmer({"Каждый", "охотник", "желает", "знать"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"кажд", "охотник", "жела", "знат"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}

TEST(PortersStemmerTest, StemmizeTest2) {
    PortersStemmer stemmer({"Должны", "быть", "сформулированы", "требования", "проекту"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"должн", "быт", "сформулирова", "требован", "проект"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}

TEST(PortersStemmerTest, StemmizeTest3) {
    PortersStemmer stemmer({"Желательно", "подготовить", "основые", "сценарии", "взаимодействия"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"желательн", "подготов", "основ", "сценар", "взаимодейств"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}

TEST(PortersStemmerTest, StemmizeTest4) {
    PortersStemmer stemmer({"Поскольку"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"поскольк"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}

TEST(PortersStemmerTest, StemmizeTest4) {
    PortersStemmer stemmer({"выцвевший"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"выцвевш"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}
