#include "server.hpp"
#include <boost/json/src.hpp>
#include "DBManager.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio; 
using tcp = boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    // Check command line arguments.
    if (argc != 4)
    {
        std::cerr <<
            "Usage: websocket-server-async <address> <port> <threads>\n" <<
            "Example:\n" <<
            "    websocket-server-async 0.0.0.0 8080 1\n";
        return EXIT_FAILURE;
    }
    std::cout << "Starting server" << std::endl;
    auto const address = net::ip::make_address(argv[1]);
    auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
    auto const threads = std::max<int>(1, std::atoi(argv[3]));

    // The io_context is required for all I/O
    net::io_context ioc{threads};

    std::shared_ptr<IDatabaseManager> database_manager_ptr(new DBManager());
    //std::shared_ptr<Recommendation> recommendation_ptr(new Recommendation());

    //std::shared_ptr<IRequestHandler> request_handler_ptr(new RequestHandler(database_manager_ptr, recommendation_ptr));
    // Create and launch a listening port
    //std::make_shared<Server>(ioc, tcp::endpoint{address, port}, request_handler_ptr)->run();
    std::make_shared<Server>(ioc, tcp::endpoint{address, port}, database_manager_ptr)->run();

    // Run the I/O service on the requested number of threads
    std::vector<std::thread> v;
    v.reserve(threads - 1);
    for(auto i = threads - 1; i > 0; --i)
        v.emplace_back(
        [&ioc]
        {
            ioc.run();
        });
    ioc.run();

    return EXIT_SUCCESS;
}
