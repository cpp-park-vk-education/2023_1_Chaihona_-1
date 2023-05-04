#pragma once

#include <memory>
#include <boost/beast.hpp>
#include "database_manager.hpp"

class IRequestHandler {
public:
  virtual boost::beast::http::response<boost::beast::http::string_body> ReadRequest(std::string json) = 0;
private:
  virtual boost::beast::http::response<boost::beast::http::string_body> GenerateResponse() = 0;
  virtual void JsonParser(std::string json) = 0;
  virtual void CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) = 0;
};

class RequestHandler : public IRequestHandler {
public:
  RequestHandler(std::shared_ptr<IDatabaseManager> database_manager, std::shared_ptr<IRecommendation> recommendation) {}
  virtual boost::beast::http::response<boost::beast::http::string_body> ReadRequest(std::string json) override {return boost::beast::http::response<boost::beast::http::string_body>(); }
private:
  virtual boost::beast::http::response<boost::beast::http::string_body> GenerateResponse() override {return boost::beast::http::response<boost::beast::http::string_body>();}
  virtual void JsonParser(std::string json) override {}
  virtual void CalculateRecommendations(Profile& profile, std::vector<Profile>& recommended_profiles) override {}
  /*Request Parametres*/
};
