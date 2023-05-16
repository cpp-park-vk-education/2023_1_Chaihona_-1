#include "recommendation.hpp"

void Recommendation::forms_to_users() {
    user_.id_ =  form_.getId();
    user_.text_ = form_.getDescription();
    std::vector<UserInterest> interests = form_.getInterests();
    for (UserInterest& interest : interests) {
        user_.interest_vect_.push_back(interest.getRate());
    }
}

void Recommendation::users_to_forms() {}

void Recommendation::vectorize_profile_text() {
    std::ifstream docs(DOCS_FILE);
    if(!docs.is_open()) {
        std::cerr << DOCS_FILE << " could not be opened for reading!" << std::endl;
    }
    CleanTokenizer tokenizer;
    PortersStemmer stemmer;
    VectorizerTFIDF vectorizer(docs);
    vectorizer.set_text(user_.text_);
    vectorizer.vectorize(tokenizer, stemmer);
    user_.text_vect_ = vectorizer.get_vect();
}

void Recommendation::recommend() {
    Filter filter(user_, recommended_users_);
    CosSimilarityCalculator calculator;
    filter.calculate_users_similiarity(calculator);
    recommended_users_ = filter.get_recommended_users();
    std::sort(recommended_users_.begin(), recommended_users_.end(), std::greater<UserForm>());
}