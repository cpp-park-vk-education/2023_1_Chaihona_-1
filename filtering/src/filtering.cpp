#include "filtering.hpp"

void CosSimilarityCalculator::set_vectors(std::vector<double>& first, std::vector<double>& second) {
    first_ = first;
    second_ = second;
}

double CosSimilarityCalculator::get_similarity() {
    return cos_similarity_;
}

void CosSimilarityCalculator::calculate() {
    double dot_product = 0.0;
    double first_length = 0.0;
    double second_length = 0.0;

    for (size_t i = 0; i < first_.size(); ++i) {
        dot_product += first_[i] * second_[i];
        first_length += std::pow(first_[i], 2);
        second_length += std::pow(second_[i], 2);
    }

    first_length = std::sqrt(first_length);
    second_length = std::sqrt(second_length);

    cos_similarity_ = dot_product / (first_length * second_length);
}

void Filter::calculate_users_similiarity(SimilarityCalculator& sim_calculator) {
    for (UserForm& cur_user : recommended_users_) {
        sim_calculator.set_vectors(user_.interest_vect_, cur_user.interest_vect_);
        sim_calculator.calculate();
        cur_user.interest_similarity_ = sim_calculator.get_similarity();

        sim_calculator.set_vectors(user_.text_vect_, cur_user.text_vect_);
        sim_calculator.calculate();
        cur_user.text_similarity_ = sim_calculator.get_similarity();

        cur_user.similarity_ = (cur_user.interest_similarity_ + cur_user.text_similarity_) / 2;
    }    
}

std::vector<UserForm> Filter::get_recommended_users() {
    return recommended_users_;   
}
