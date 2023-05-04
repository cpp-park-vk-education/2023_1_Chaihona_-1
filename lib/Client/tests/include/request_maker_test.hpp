#pragma once

#include <gmock/gmock.h>
#include "request_maker.hpp"
#include "client.hpp"

class GMockClient : public IClient {
public:
  MOCK_METHOD(void, run, (), (override));
  MOCK_METHOD(void, set_request, (std::string json_path), (override));
private:
  MOCK_METHOD(void, on_resolve, (), (override));
  MOCK_METHOD(void, on_connect, (), (override));
  MOCK_METHOD(void, on_write, (), (override));
  MOCK_METHOD(void, on_read, (), (override));
};