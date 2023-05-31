#include <gtest/gtest.h>
#include "filtering.hpp"

TEST(CosSimilarityCalculatorTest, EmptyVectors) {
    std::vector<double> first {};
    std::vector<double> second {};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 1;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, EqualVectors) {
    std::vector<double> first {1, 2, 3, 4, 5};
    std::vector<double> second {1, 2, 3, 4, 5};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 1;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, VeryCloseVectors) {
    std::vector<double> first {1, 2, 2, 4, 5};
    std::vector<double> second {1, 2, 3, 4, 7};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.986491;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, CloseVectors) {
    std::vector<double> first {1, 2, 2, 4, 5};
    std::vector<double> second {-3, 0, 4, 7, 9};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.88602;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, OppositeVectors) {
    std::vector<double> first {1, 2, 3, 4, 5};
    std::vector<double> second {-1, -2, -3, -4, -5};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = -1;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, SomeVectors1) {
    std::vector<double> first {1,-1, 3, 3};
    std::vector<double> second {0, 1, 2, 0};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.5;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(FilterTest, Filter) {
    UserForm user;
    user.text_vect_ = {1.0, 2.0, 3.0, 4.0};
    user.interest_vect_ = {1.0, 2.0, 3.0, 4.0};


    std::vector<UserForm> rec_users;
    for (int i = 0; i < 2; i++) {
        UserForm user_tmp;
        user_tmp.text_vect_ = {10.0+i, 2.0+i, 30.0+i, 4.0+i};
        user_tmp.interest_vect_ = {10.0+i, 2.0+i, 30.0+i, 4.0+i};
        rec_users.push_back(user_tmp);
    }

    CosSimilarityCalculator calc;
    Filter filt(user, rec_users);

    filt.calculate_users_similiarity(calc);
    rec_users = std::move(filt.get_recommended_users());

    UserForm expect_user_0;
    expect_user_0.similarity_ = 0.685994;
    UserForm expect_user_1;
    expect_user_1.similarity_ = 0.710478;
    
    EXPECT_EQ(rec_users[0].similarity_, expect_user_0.similarity_);
    EXPECT_EQ(rec_users[1].similarity_, expect_user_1.similarity_);
}
