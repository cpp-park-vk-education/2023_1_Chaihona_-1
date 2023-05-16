#pragma once

#include <gmock/gmock.h>
#include "request_handler.hpp"

/*class GMockSession : public ISession{
public:
  MOCK_METHOD(void, run, (), (override));
  MOCK_METHOD(void, do_read, (), (override));
  MOCK_METHOD(void, on_read, (), (override));
  MOCK_METHOD(void, send_response, (), (override));
  MOCK_METHOD(void, do_close, (), (override));
  MOCK_METHOD(void, handle_request, (), (override));
};*/

class GMockDatabaseManager : public IDatabaseManager {
public:
  MOCK_METHOD(Profile, authorise, (User user), (override));
  MOCK_METHOD(std::vector<Profile>, getRecomendations, (Profile profile), (override));
  MOCK_METHOD(unsigned, addUser, (User user), (override));
  MOCK_METHOD(bool, makeMatch, (unsigned, unsigned), (override));
  MOCK_METHOD(bool, breakMatch, (unsigned, unsigned), (override));
  MOCK_METHOD(Form, getUserForm, (unsigned id), (override));
  MOCK_METHOD(std::vector<Form>, getRecommendForms, (Form), (override));
  MOCK_METHOD(void, editRecommendations, (unsigned, std::vector<Profile>&), (override));
  MOCK_METHOD(void, editUser, (User), (override));
  MOCK_METHOD(void, editForm, (Form), (override));
};

class GMockRecommendation : public IRecommendation {
public:
  MOCK_METHOD(void, recommend, (), (override));
  MOCK_METHOD(void, VectorizeProfileText, (), (override));
  GMockRecommendation(Profile& profile, std::vector<Profile>& recommended_profiles) {}
  GMockRecommendation() {}
};