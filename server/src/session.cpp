#include "session.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio; 
using tcp = boost::asio::ip::tcp;

void fail(beast::error_code ec, char const* what) {
  std::cerr << what << ": " << ec.message() << "\n";
}

Session::Session(tcp::socket&& socket, std::shared_ptr<IDatabaseManager> dmp): ws_(std::move(socket)), request_handler_ptr_(new RequestHandler(dmp/*, std::make_unique<IRecommendation>(new Recommendation())*/)) {}

void Session::run() {
  net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Session::on_run, shared_from_this()));
}

void Session::on_run() {
  ws_.set_option(websocket::stream_base::timeout::suggested(beast::role_type::server));

  ws_.set_option(websocket::stream_base::decorator(
    [](websocket::response_type& res) {
      res.set(http::field::server,std::string(BOOST_BEAST_VERSION_STRING) + " websocket-server-async");
    }));

  ws_.async_accept(beast::bind_front_handler(&Session::on_accept, shared_from_this()));
}

void Session::on_accept(beast::error_code ec) {
  if(ec)
    return fail(ec, "accept");

  do_read();
}

void Session::do_read() {
  ws_.async_read(buffer_, beast::bind_front_handler(&Session::on_read, shared_from_this())); 

  // http::async_read(beast::get_lowest_layer(ws_), buffer_, req_, beast::bind_front_handler(&Session::on_read, shared_from_this()));
}

void Session::on_read(beast::error_code ec, std::size_t bytes_transferred) {
  std::cout << req_.body() << std::endl;
  boost::ignore_unused(bytes_transferred);

  if(ec == websocket::error::closed)
    return;

  if(ec)
    fail(ec, "read");

  ws_.text(ws_.got_text());
  //ws_.async_write(buffer_.data(), beast::bind_front_handler(&Session::handle_request, shared_from_this()));
  net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Session::handle_request, shared_from_this()));
}

void Session::handle_request() {
  res_ = request_handler_ptr_->ReadRequest(beast::buffers_to_string(buffer_.data()));
  // res_ = request_handler_ptr_->ReadRequest(req_.body());
  net::dispatch(ws_.get_executor(), beast::bind_front_handler(&Session::send_response, shared_from_this()));
}

void Session::send_response() {

  std::cout << beast::buffers_to_string(buffer_.data()) << std::endl; 
  ws_.async_write(buffer_.data(), beast::bind_front_handler(&Session::on_write, shared_from_this())); 
  // http::async_write(beast::get_lowest_layer(ws_), res_, beast::bind_front_handler(&Session::on_write, shared_from_this()));
}

void Session::on_write(beast::error_code ec, std::size_t bytes_transferred) {
  boost::ignore_unused(bytes_transferred);

  if(ec)
    return fail(ec, "write");


  buffer_.consume(buffer_.size());

  do_read();
}