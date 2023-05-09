#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include "request_handler.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

void fail(beast::error_code ec, char const* what);

class ISession {
public:
  virtual void run() = 0;
  virtual void on_run() = 0;
  virtual void on_accept(beast::error_code ec) = 0;
  virtual void do_read() = 0;
  virtual void on_read(beast::error_code ec, std::size_t bytes_transferred) = 0;
  virtual void handle_request() = 0;
  virtual void send_response() = 0;
  virtual void on_write(beast::error_code ec, std::size_t bytes_transferred) = 0;
  //virtual void do_close() = 0; ???
};

class Session : public std::enable_shared_from_this<Session>, public ISession {
  websocket::stream<beast::tcp_stream> ws_;
  beast::flat_buffer buffer_;
  std::shared_ptr<IRequestHandler> request_handler_ptr_;
  std::string response_;
  //http::request<http::string_body> req_;

public:
  explicit Session(tcp::socket&& socket, std::shared_ptr<IRequestHandler> rhp);

  virtual void run() override;
  virtual void on_run() override;
  virtual void on_accept(beast::error_code ec) override;
  virtual void do_read() override;
  virtual void on_read(beast::error_code ec, std::size_t bytes_transferred) override;
  virtual void handle_request() override;
  virtual void send_response() override;
  virtual void on_write(beast::error_code ec, std::size_t bytes_transferred) override;
};