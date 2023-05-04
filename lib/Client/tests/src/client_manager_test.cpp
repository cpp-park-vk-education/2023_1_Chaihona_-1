#include <fstream>
#include "client_manager_test.hpp"
#include "request_maker_test.hpp"

TEST(ClientManegerTest, LogInCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker()); //need fix
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.log_in("chel@mail.ru", "12345");

  std::fstream expect_file;
  expect_file.open("LogInCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"log in",\n\t"email":"chel@mail.ru",\n\t"password":"12345"\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}

TEST(ClientManegerTest, LogOutCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker());
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.log_out(21415);

  std::fstream expect_file;
  expect_file.open("LogOutCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"log out",\n\t"id":21415\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}

TEST(ClientManegerTest, RegistrationCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker());
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.registration("chel@mail.ru", "12345");

  std::fstream expect_file;
  expect_file.open("RegistrationCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"registration",\n\t"email":"chel@mail.ru",\n\t"password":"12345"\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}

TEST(ClientManegerTest, LikeCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker());
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.like(54321, 12345);

  std::fstream expect_file;
  expect_file.open("LikeCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"like",\n\t"author_id":54321,\n\t"target_id":12345\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}

TEST(ClientManegerTest, DislikeCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker());
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.dislike(54321, 12345);

  std::fstream expect_file;
  expect_file.open("DislikeCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"dislike",\n\t"author_id":54321,\n\t"target_id":12345\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}

TEST(ClientManegerTest, GetNextProfileCase){
  auto request_maker_ptr =  std::make_unique<IRequestMaker>(GMockRequestMaker());
  IRequestMaker* request_maker_row = request_maker_ptr.get();

  ClientManager client_manager(std::move(request_maker_ptr));

  EXPECT_CALL(*dynamic_cast<GMockRequestMaker*>(request_maker_row), MakeRequest("request.json"));

  client_manager.getNextProfile(54321);

  std::fstream expect_file;
  expect_file.open("GetNextProfileCase.json");

  std::string expect = "";
  std::string tmp;
  while (getline(expect_file, tmp))
  {
    expect += tmp;
  }
  expect_file.close();
  
  std::fstream actual_file; 
  actual_file.open("request.json"); // expected {\t"request":"get next profile",\n\t"author_id":54321\n}
  EXPECT_TRUE(actual_file.is_open()); // It's bad check because MakeRequest() will overwrite old file in each test

  std::string actual = "";
  while (getline(actual_file, tmp))
  {
    actual += tmp;
  }
  actual_file.close();

  EXPECT_STREQ(expect.c_str(), actual.c_str()); // may be should check in different way, it could be different formats (with \n or without)
}