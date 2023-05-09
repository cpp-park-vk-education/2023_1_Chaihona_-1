#pragma once
#include <gmock/gmock.h>
#include "client_manager.hpp"
/*
class GMockRequestMaker : public IRequestMaker {
public:
  MOCK_METHOD(void, MakeRequest, (std::string), (override));
};

class GMockClientManager : public IClientManager { 
public:
  MOCK_METHOD(void, log_in, (std::string email, std::string password), (override));
  MOCK_METHOD(void, log_out, (unsigned id), (override));
  MOCK_METHOD(void, registration, (std::string email, std::string password), (override));
  MOCK_METHOD(void, like, (unsigned author_id, unsigned target_id), (override));
  MOCK_METHOD(void, dislike, (unsigned author_id, unsigned target_id), (override));
  MOCK_METHOD(void, getNextProfile, (unsigned author_id), (override));
};
*/