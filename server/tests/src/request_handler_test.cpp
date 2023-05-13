#include <gtest/gtest.h>
#include "request_handler_test.hpp"

TEST(RequestHandlerTest, LogInCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();
  
  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), authorise(User{"chel@mail.ru", "12345"}));

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"log in",\n\t"email":"chel@mail.ru",\n\t"password":"12345"\n})");
  
  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, LogOutCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  //EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), ... );
  // I should check only response in this case

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"log out",\n\t"id":21415\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, RegistrationCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), addUser(User{"chel@mail.ru", "12345"}));

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"registration",\n\t"email":"chel@mail.ru",\n\t"password":"12345"\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, LikeCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), makeMatch(12345, 54321));

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"like",\n\t"author_id":54321,\n\t"target_id":12345\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, MatchCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  auto tmp = request_handler.ReadRequest(R"({\n\t"request":"like",\n\t"author_id":54321,\n\t"target_id":12345\n})");
  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), getUserForm(54321));
  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"like",\n\t"author_id":12345,\n\t"target_id":54321\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
  expect_response.body() = R"({\n\t"event":"match",\n\t"form":\n\t{\n\t\t"hobby":"chess"\n\t}\n})";
  EXPECT_EQ(expect_response.body(), actual_response.body());
}

TEST(RequestHandlerTest, DislikeCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), breakMatch(12345, 54321));

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"dislike",\n\t"author_id":54321,\n\t"target_id":12345\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, GetNextProfilesCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), getUserForm(54321));
  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), getRecommendForms(Form{54321}));
  EXPECT_CALL(*dynamic_cast<GMockRecommendation*>(recommendation_row), recommend);
  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), editRecommendations);
  

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(R"({\n\t"request":"get next profiles",\n\t"author_id":54321\n})");

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
  EXPECT_NE(expect_response.body(), actual_response.body());
}

TEST(RequestHandlerTest, EditUserCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), editUser(User{"newmail@mail.ru", "newpassword"}));

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(
    R"({\n\t"request":"edit user",\n\t"user":\n\t{\t\t"email":"newmail@mail.ru",\n\t\t"password":"newpassword"\n\t}\n})"
  );

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
}

TEST(RequestHandlerTest, EditFormCase) {
  std::shared_ptr<IDatabaseManager> database_manager_ptr(new GMockDatabaseManager());
  IDatabaseManager* database_manager_row = database_manager_ptr.get();

  std::shared_ptr<IRecommendation> recommendation_ptr(new GMockRecommendation());
  IRecommendation* recommendation_row = recommendation_ptr.get();

  RequestHandler request_handler(database_manager_ptr, recommendation_ptr);

  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), editForm(Form{1/*interests*/}));
  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), getRecommendForms(Form{1/*it must be user form with his interests and etc.*/}));
  EXPECT_CALL(*dynamic_cast<GMockRecommendation*>(recommendation_row), recommend);
  EXPECT_CALL(*dynamic_cast<GMockDatabaseManager*>(database_manager_row), editRecommendations);
  

  boost::beast::http::response<boost::beast::http::string_body> actual_response = request_handler.ReadRequest(
    R"({\t"request":"edit form",\n\t"form":\n\t{\t\t"hobby":"ping pong"\n\t}\n})"
  );

  boost::beast::http::response<boost::beast::http::string_body> expect_response;
  expect_response.version(11);
  expect_response.result(boost::beast::http::status::ok);
  EXPECT_EQ(expect_response.version(), actual_response.version());
  EXPECT_EQ(expect_response.result(), actual_response.result());
  EXPECT_EQ(expect_response.reason(), actual_response.reason());
  EXPECT_NE(expect_response.body(), actual_response.body());
}