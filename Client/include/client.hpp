#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <queue>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

void fail(beast::error_code ec, char const* what);

class IClient { 
public:
  virtual ~IClient() {} 
  virtual void run(char const* host, char const* port, char const* text) = 0;
  virtual void on_resolve(beast::error_code ec, tcp::resolver::results_type results) = 0;
  virtual void on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep) = 0;
  virtual void set_request(std::string json) = 0;

  //virtual void wait_request() = 0;

  virtual void on_handshake(beast::error_code ec) = 0;
  virtual void on_wait() = 0;
  virtual void on_write(beast::error_code ec, std::size_t bytes_transferred) = 0;
  virtual void on_read(beast::error_code ec, std::size_t bytes_transferred) = 0;
  virtual void close() = 0;
  virtual void on_close(beast::error_code ec) = 0;

  virtual std::queue<std::string>& getResponses() = 0;
};

class Client : public std::enable_shared_from_this<Client>, public IClient {
  tcp::resolver resolver_;
  websocket::stream<beast::tcp_stream> ws_;
  beast::flat_buffer buffer_;
  std::string host_;
  std::string text_;
  bool new_request_flag;
  std::queue<std::string> res_;
  
public:

  explicit Client(net::io_context& ioc);

  virtual void run(char const* host, char const* port, char const* text) override;
  virtual void on_resolve(beast::error_code ec, tcp::resolver::results_type results) override;
  virtual void on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep) override;
  virtual void set_request(std::string json) override;

  //template <typename AccpetHandler>
  void wait_request();

  virtual void on_handshake(beast::error_code ec) override;
  virtual void on_wait() override;
  virtual void on_write(beast::error_code ec, std::size_t bytes_transferred) override;
  virtual void on_read(beast::error_code ec, std::size_t bytes_transferred) override;
  virtual void close() override;
  virtual void on_close(beast::error_code ec) override;

  virtual std::queue<std::string>& getResponses() override;
};