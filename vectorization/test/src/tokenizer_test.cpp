#include <gtest/gtest.h>
#include "text_processing.hpp"

TEST(CleanTokenizerTest, SetEmptyText) {
    CleanTokenizer tokenizer;
    tokenizer.set_text("");
    std::string expect_text {""};
    EXPECT_EQ(tokenizer.get_text(), expect_text);
}

TEST(CleanTokenizerTest, SetSomeText) {
    CleanTokenizer tokenizer;
    tokenizer.set_text("Каждый охотник желает знать, где сидит фазан");
    std::string expect_text {"Каждый охотник желает знать, где сидит фазан"};
    EXPECT_EQ(tokenizer.get_text(), expect_text);
}

TEST(CleanTokenizerTest, EmptyStrWithSet) {
    CleanTokenizer tokenizer;
    tokenizer.set_text("");
    tokenizer.tokenize();
    std::vector<std::string> expect_vect {""};
    EXPECT_EQ(tokenizer.get_tokens(), expect_vect);
}

TEST(CleanTokenizerTest, EmptyStrWithConstructor) {
    CleanTokenizer tokenizer("");
    tokenizer.tokenize();
    std::vector<std::string> expect_vect {""};
    EXPECT_EQ(tokenizer.get_tokens(), expect_vect);
}

TEST(CleanTokenizerTest, TokenizeTest) {
    CleanTokenizer tokenizer("Провожу тестирование функции токенизации текста");
    tokenizer.tokenize();
    std::vector<std::string> expect_vect {"Провожу", "тестирование", "функции", "токенизации", "текста"};
    EXPECT_EQ(tokenizer.get_tokens(), expect_vect);
}
