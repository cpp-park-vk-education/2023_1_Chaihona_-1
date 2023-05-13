#include <gtest/gtest.h>
#include "tfidf_vectorization.hpp"

TEST(TestVectorizerTFIDF, CalculateTF1) {
    std::string text = "участник команды пишет тесты для классов которые пишет";
    std::string word = "пишет";
    VectorizerTFIDF vectorizer(text);
    SplitTokenizer tokenizer;
    PortersStemmer stemmer;
    vectorizer.vectorize(tokenizer, stemmer);
    double expect_tf = 0.25;
    EXPECT_EQ(vectorizer.get_tf(word), expect_tf);
}

TEST(TestVectorizerTFIDF, CalculateTF2) {
    std::string text = "каждый участник пишет тесты для классов за которые отвечает каждый участник получает индивидуальную оценку";
    std::string word = "каждый";
    VectorizerTFIDF vectorizer(text);
    SplitTokenizer tokenizer;
    PortersStemmer stemmer;
    vectorizer.vectorize(tokenizer, stemmer);
    double expect_tf = 0.143;
    EXPECT_EQ(vectorizer.get_tf(word), expect_tf);
}

TEST(TestVectorizerTFIDF, CalculateTF3) {
    std::string text = "участник участник";
    std::string word = "участник";
    VectorizerTFIDF vectorizer(text);
    SplitTokenizer tokenizer;
    PortersStemmer stemmer;
    vectorizer.vectorize(tokenizer, stemmer);
    double expect_tf = 1;
    EXPECT_EQ(vectorizer.get_tf(word), expect_tf);
}

TEST(TestVectorizerTFIDF, CalculateVect1) {
    std::string text = "cемь раз отмерь";
    VectorizerTFIDF vectorizer(text);
    SplitTokenizer tokenizer;
    PortersStemmer stemmer;
    vectorizer.set_filename("docs.txt");
    vectorizer.vectorize(tokenizer, stemmer);
    std::vector<double> expect_vect {0, 0.54, 0, 0.54, 0.65};
    EXPECT_EQ(vectorizer.get_vect(), expect_vect);
}

TEST(TestVectorizerTFIDF, CalculateVect2) {
    std::string text = "cемь раз отмерь один раз отрежь";
    VectorizerTFIDF vectorizer(text);
    SplitTokenizer tokenizer;
    PortersStemmer stemmer;
    vectorizer.set_filename("docs.txt");
    vectorizer.vectorize(tokenizer, stemmer);
    std::vector<double> expect_vect {0.38, 0.31, 0.47, 0.62, 0.38};
    EXPECT_EQ(vectorizer.get_vect(), expect_vect);
}