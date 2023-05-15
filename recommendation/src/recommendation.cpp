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

void Recommendation::vectorize_profile() {
    std::ifstream docs(DOCS_FILE);
    if(!docs.is_open()) {
        std::cerr << docs << " could not be opened for reading!" << std::endl;
    }
    VectorizerTFIDF& vectorizer(docs);
    vectorizer.set_text(user_.text_);
    vectorizer.vectorize();
    user_.text_vect_ = vectorizer.get_vect();
}

void Recommendation::vectorize_profiles() {
    std::ifstream docs(DOCS_FILE);
    if(!docs.is_open()) {
        std::cerr << docs << " could not be opened for reading!" << std::endl;
    }
    VectorizerTFIDF& vectorizer(docs);
    for (UserForm& user : recommended_users_) {
        vectorizer.set_text(user.text_);
        vectorizer.vectorize();
        user.text_vect_ = vectorizer.get_vect();
    }
}

void Recommendation::recommend() {
    Filter filter(user_, recommended_users_);
    filter.calculate_users_similiarity();
    recommended_users_ = filter.get_recommended_users();
    std::sort(recommended_users_.begin(), recommended_users_.end(), greater<UserForm>());
}
