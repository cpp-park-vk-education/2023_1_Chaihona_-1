#include "server.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio; 
using tcp = boost::asio::ip::tcp;

Server::Server(net::io_context& ioc, tcp::endpoint endpoint, std::shared_ptr<IRequestHandler> rhp): ioc_(ioc), acceptor_(ioc), request_handler_ptr_(rhp) {
    beast::error_code ec;

    acceptor_.open(endpoint.protocol(), ec);
    if(ec) {
        fail(ec, "open");
        return;
    }

    acceptor_.set_option(net::socket_base::reuse_address(true), ec);
    if(ec) {
        fail(ec, "set_option");
        return;
    }

    acceptor_.bind(endpoint, ec);
    if(ec) {
        fail(ec, "bind");
        return;
    }

    acceptor_.listen(
        net::socket_base::max_listen_connections, ec);
    if(ec) {
        fail(ec, "listen");
        return;
    }
}

void Server::run() {
    do_accept();
}

void Server::do_accept() {
    acceptor_.async_accept(net::make_strand(ioc_), beast::bind_front_handler(&Server::on_accept, shared_from_this()));
}

void Server::on_accept(beast::error_code ec, tcp::socket socket) {
    if(ec) {
        fail(ec, "accept");
    }
    else {
        std::make_shared<Session>(std::move(socket), request_handler_ptr_)->run();
    }

    do_accept();
}
