#include "request_maker_test.hpp"

TEST(RequestMakerTest, RequestMakeCase){
  auto client_ptr = std::make_unique<IClient>(GMockClient());
  auto client_row = client_ptr.get();

  RequestMaker request_maker(std::move(client_ptr));

  EXPECT_CALL(*dynamic_cast<GMockClient*>(client_row), set_request("request.json"));
  EXPECT_CALL(*dynamic_cast<GMockClient*>(client_row), run);

  request_maker.MakeRequest("request.json");
}