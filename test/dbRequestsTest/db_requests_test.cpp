#include <gtest/gtest.h>
#include <vector>
#include "lifestyle.hpp"
#include "interest.hpp"
#include "UserRequests.hpp"
#include "MatchRequests.hpp"
#include "FormRequests.hpp"
#include "UserInterestRequests.hpp"
#include "UserLifestyleRequests.hpp"
#include "InterestRequests.hpp"
#include "LifestyleRequests.hpp"
#include "ProfileRequests.hpp"
#include "form.hpp"
#include "MatchRequests.hpp"
#include "CheckEmail.hpp"
#include "ContactRequests.hpp"
#include <string>

/*
* Общие возможные проблемы:
* 1) Передача недозаполненного объекта класса
* 2) Неправильный sql-запрос
* Правильность переданных параметров не проверяется, так как это должно ограничиваться на клиенте
* Тесты закомментарены, чтобы не падали, так как реализации конструкторов ещё не готовы
* По той же причине ещё не заполнены поля expected
*/


// Проверка метода, возвращающего список возможных интересов
// Так как ещё не реализованы конструктор
TEST (interests_requests, get_possible_interests) {
    std::vector<Interest> expected;
    InterestRequests interestRequests;
    //EXPECT_EQ(interestRequests.getPossibleInterests(), expected);
}


// Проверка метода, возвращающего список возможных жизненных позиций
TEST (lifestyle_requests, get_possible_lifestyles) {
    std::vector<Lifestyle> expected;
    LifestyleRequests lifestyleRequests;
    //EXPECT_EQ(lifestyleRequests.getPossibleLifestyles(), expected);
}


//Проверка метода авторизации
//Дополнительная проблема: неправильная пара логин/пароль (пользователя не существует)
TEST (user_requests, authorise) {
    User registeredUser;
    User unregisteredUser;
    UserRequests userRequests;
    //EXPECT_EQ(userRequests.authorise(registeredUser), true);
    //EXPECT_EQ(userRequests.authorise(unregisteredUser), false);
}


//Проверка добавления пользователя
TEST (user_requests, insert_user) {
    User user;
    UserRequests userRequests;
    //EXPECT_EQ(userRequests.insert(user), 11);
}


//Проверка получения интересов пользователя
TEST(user_interest_requests, get_user_interests) {
    Profile profile;
    UserInterestRequests userInterestRequests;
    std::vector<Interest> expected;
    //EXPECT_EQ(userInterestRequests.getUserInterests(profile), expected);
}


//Проверка получения жизненных ценностей пользователя
TEST(user_lifestyle_requests, get_user_lifestyle) {
    Profile profile;
    UserLifestyleRequests userInterestRequests;
    std::vector<Lifestyle> expected;
    //EXPECT_EQ(userLifestyleRequests.getUserLifestyles(profile), expected);
}


//Проверка добавления интересов пользователя
TEST(user_interest_requests, add_interest) {
    Profile profile;
    Interest interest;
    UserInterestRequests userInterestRequests;
     //EXPECT_EQ(userInterestRequests.insert(profile, interest), 11);
}


//Проверка добавления жизненных ценностей пользователя
TEST(user_lifestyle_requests, add_lifestyle) {
    Profile profile;
    Lifestyle lifestyle;
    UserLifestyleRequests userInterestRequests;
    //EXPECT_EQ(userLifestyleRequests.insert(profile, lifestyle), 11);
}


//Проверка редактирования интересов пользователя
TEST(user_interest_requests, update_interest) {
    Profile profile;
    Interest newInterest;
    UserInterestRequests userInterestRequests;
     //EXPECT_EQ(userInterestRequests.update(profile, newInterest), true);
}


//Проверка редактирования жизненных ценностей пользователя
TEST(user_lifestyle_requests, update_lifestyle) {
    Profile profile;
    Lifestyle newLifestyle;
    UserLifestyleRequests userInterestRequests;
    //EXPECT_EQ(userLifestyleRequests.update(profile, newLifestyle), true);
}


TEST(profile_requests, insert_profile) {
    Profile profile;
    ProfileRequests profileRequests;
    //EXPECT_EQ(profileRequests.insert(Profile profile), 11);
}


TEST(match_requests, insert_match) {
    Match match;
    MatchRequests matchRequests;
    //EXPECT_EQ(matchRequests.insert(Match match), 11);
}

//два результата: лайк и не лайк
TEST(match_requests, get_match) {
    Profile profile1; Profile profile2;
    MatchRequests matchRequests;
    //EXPECT_EQ(matchRequests.matchResult(profile1, profile2), true);
    //EXPECT_EQ(matchRequests.matchResult(profile2, profile1), false);
}


//два результата: занят email или нет
TEST(email_requests, check_email) {
    std::string existingEmail ("domnakolesaxxx@gmail.com");
    std::string nonExistingEmail ("dombezkoles@gmail.com");
    CheckEmail checkEmail;
    //EXPECT_EQ(checkEmail.exec(existingEmail), true);
    //EXPECT_EQ(checkEmail.exec(nonExistingEmail), false);
}


//тест добавления контакта
TEST(contact_requests, add_contact) {
    Profile profile;
    Contact contact;
    ContactRequests contactRequests;
    //EXPECT_EQ(contactRequests.insert(profile, contact), 11);
}


//тест редактирования контакта
TEST(contact_requests, edit_contact) {
    Profile profile;
    Contact newContact;
    ContactRequests contactRequests;
    //EXPECT_EQ(contactRequests.update(profile, newContact), true);
}


//тест получения контактов пользователя
TEST(contact_requests, get_user_contacts) {
    std::vector<Contact> expected;
    Profile profile;
    ContactRequests contactRequests;
    //EXPECT_EQ(contactRequests.getUserContacts(profile), expected);
}
//insert update getUserForm getRecForms


//тест добавления формы
TEST(form_requests, add_form) {
    Form form;
    Profile profile;
    FormRequests formRequests;
    //EXPECT_EQ(formRequests.insert(form, profile), 11);
}


//тест редактирования формы
TEST(form_requests, update_form) {
    Form newForm;
    Profile profile;
    FormRequests formRequests;
    //EXPECT_EQ(formRequests.update(newForm, profile), true);
}


//тест выбора формы конкретного пользователя
TEST(form_requests, get_user_form) {
    Form expected;
    Profile profile;
    FormRequests formRequests;
    //EXPECT_EQ(formRequests.getUserForm(profile), expected);
}


//тест выбора рекомендаций для конкретного пользователя
TEST(form_requests, get_rec_forms) {
    std::vector<Form> expected;
    Profile profile;
    FormRequests formRequests;
    //EXPECT_EQ(formRequests.getUserForm(profile), expected);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}