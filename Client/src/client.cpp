#include "client.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

void fail(beast::error_code ec, char const* what) {
    std::cerr << what << ": " << ec.message() << "\n";
}

Client::Client(net::io_context& ioc): resolver_(net::make_strand(ioc)), ws_(net::make_strand(ioc)), new_request_flag(false), res_() {}

void Client::run(char const* host, char const* port, char const* text) {
    host_ = host;
    text_ = text;

    resolver_.async_resolve(
      host,
      port,
      beast::bind_front_handler(
        &Client::on_resolve,
        shared_from_this()));
}

void Client::on_resolve(beast::error_code ec, tcp::resolver::results_type results) {
    if(ec)
        return fail(ec, "resolve");

    beast::get_lowest_layer(ws_).expires_after(std::chrono::seconds(30));

    beast::get_lowest_layer(ws_).async_connect(
      results,
      beast::bind_front_handler(
        &Client::on_connect,
        shared_from_this()));
}

void Client::on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep) {
    if(ec)
        return fail(ec, "connect");

    // Turn off the timeout on the tcp_stream, because
    // the websocket stream has its own timeout system.
    std::cout << "on_connect\n";
    beast::get_lowest_layer(ws_).expires_never();

    // Set suggested timeout settings for the websocket
    ws_.set_option(
      websocket::stream_base::timeout::suggested(
        beast::role_type::client));

    // Set a decorator to change the User-Agent of the handshake
    ws_.set_option(websocket::stream_base::decorator(
        [](websocket::request_type& req) {
          req.set(http::field::user_agent,
            std::string(BOOST_BEAST_VERSION_STRING) +
            " websocket-client-async");
        }));

    // Update the host_ string. This will provide the value of the
    // Host HTTP header during the WebSocket handshake.
    // See https://tools.ietf.org/html/rfc7230#section-5.4
    host_ += ':' + std::to_string(ep.port());
    // Perform the websocket handshake
    ws_.async_handshake(host_, "/",
      beast::bind_front_handler(
        &Client::on_handshake,
        shared_from_this()));
}

void Client::set_request(std::string json) {
  std::cout << "set_request" << std::endl;
  text_ = json;
  new_request_flag = true;
}

//template <typename AccpetHandler>
void Client::wait_request() {
  while (!new_request_flag) {
    //std::cout << "waiting" << std::endl;
  }
  new_request_flag = false;
  std::cout << "wait_request" << std::endl;
  //net::asio_handler_invoke(handler);
  net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Client::on_wait, shared_from_this()));
}

void Client::on_handshake(beast::error_code ec) {
    if(ec)
        return fail(ec, "handshake");
    std::cout << "handshake\n";
    //wait_request(beast::bind_front_handler(&Client::on_wait, shared_from_this()));
    net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Client::wait_request, shared_from_this()));
}

void Client::on_wait() {
  std::cout << "on wait" << std::endl;
  std::cout << text_ << std::endl;
  ws_.async_write(net::buffer(text_), beast::bind_front_handler(&Client::on_write, shared_from_this()));
  
  // auto buf = net::buffer("");
  // net::buffer_copy(&buf, &req);
  // ws_.async_write(buf, beast::bind_front_handler(&Client::on_write, shared_from_this()));

  // http::request<http::string_body> req;
  // req.body() = text_;
  // req.version(11);
  // req.method(http::verb::post);
  // req.target("/");
  // req.set(http::field::host, "127.0.0.1");
  // http::async_write(beast::get_lowest_layer(ws_), req, beast::bind_front_handler(&Client::on_write, shared_from_this()));

  //ws_.async_write(req, beast::bind_front_handler(&Client::on_write, shared_from_this()));
}

void Client::on_write(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if(ec)
        return fail(ec, "write");
    
    // Read a message into our buffer
    ws_.async_read(buffer_, beast::bind_front_handler(&Client::on_read, shared_from_this()));

    // http::async_read(beast::get_lowest_layer(ws_), buffer_, res_, beast::bind_front_handler(&Client::on_read, shared_from_this()));
}

void Client::on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);
    if(ec)
        return fail(ec, "read");
    res_.push(beast::buffers_to_string(buffer_.data()));
    std::cout << beast::buffers_to_string(buffer_.data()) << std::endl;
    buffer_.consume(buffer_.size());
    net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Client::wait_request, shared_from_this()));
}

void Client::close() {
    ws_.async_close(websocket::close_code::normal,
      beast::bind_front_handler(&Client::on_close, shared_from_this()));
}

void Client::on_close(beast::error_code ec) {
    if(ec)
        return fail(ec, "close");

    // If we get here then the connection is closed gracefully

    // The make_printable() function helps print a ConstBufferSequence
    std::cout << beast::make_printable(buffer_.data()) << std::endl;
}

std::queue<std::string>& Client::getResponses() { 
  return this->res_;
}