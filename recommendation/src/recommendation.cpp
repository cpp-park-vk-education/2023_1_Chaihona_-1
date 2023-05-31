#include "recommendation.hpp"

const std::string Recommendation::DOCS_FILE = "preprocessed_texts.txt";

void Recommendation::forms_to_users() {
    user_.id_ =  form_.getId();
    user_.text_vect_ = form_.getVectorisedText();
    std::vector<UserInterest> interests = form_.getInterests();
    for (UserInterest& interest : interests) {
        user_.interest_vect_.push_back(interest.getRate());
    }

    for (Form& form : recommended_forms_) {
        UserForm user;
        user.id_ = form.getId();
        user.text_vect_ = form_.getVectorisedText();
        std::vector<UserInterest> interest = form_.getInterests();
        for (UserInterest& inter : interest) {
            user.interest_vect_.push_back(inter.getRate());
        }
        recommended_users_.push_back(user);
        user.interest_vect_.clear();
    }
}

void Recommendation::users_to_forms() {
    std::vector<Form> rec_forms;

    for (UserForm& us : recommended_users_) {
        for (Form& form : recommended_forms_) {
            if (us.id_ == form.getId()) {
                rec_forms.push_back(form);
            }
        }
    }
    
    recommended_forms_ = rec_forms;
}

void Recommendation::vectorize_profile_text() {
    std::ifstream docs(DOCS_FILE);
    if(!docs.is_open()) {
        std::cerr << DOCS_FILE << " could not be opened for reading!" << std::endl;
    }

    user_.id_ =  form_.getId();
    user_.text_ = form_.getDescription();

    CleanTokenizer tokenizer;
    PortersStemmer stemmer;
    VectorizerTFIDF vectorizer(docs);

    vectorizer.set_text(user_.text_);
    vectorizer.vectorize(tokenizer, stemmer);
    user_.text_vect_ = vectorizer.get_vect();

    std::vector<std::string> tokens = vectorizer.get_tokens();
    std::string preproc_text;
    for (std::string str : tokens) {
        preproc_text += (str + " ");
    }

    form_.setPreworkedText(preproc_text);
    form_.setVectorisedText(user_.text_vect_);
}

void Recommendation::recommend() {
    forms_to_users();

    Filter filter(user_, recommended_users_);
    CosSimilarityCalculator calculator;

    filter.calculate_users_similiarity(calculator);
    recommended_users_ = filter.get_recommended_users();
    
    std::sort(recommended_users_.begin(), recommended_users_.end(), std::greater<UserForm>());
    users_to_forms();
}
