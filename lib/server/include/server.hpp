#pragma once

#include "session.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class IServer {
public:
  virtual ~IServer() {}
  virtual void run() = 0;

private:
  virtual void do_accept() = 0;
  virtual void on_accept(beast::error_code ec, tcp::socket socket) = 0;
};

class Server : public std::enable_shared_from_this<Server>, public IServer {
    net::io_context& ioc_;
    tcp::acceptor acceptor_;
    std::shared_ptr<IRequestHandler> request_handler_ptr_;
public:
    Server(net::io_context& ioc, tcp::endpoint endpoint, std::shared_ptr<IRequestHandler> rhp);
    virtual void run() override;

private:
    virtual void do_accept() override;
    virtual void on_accept(beast::error_code ec, tcp::socket socket) override;
};