#include "SQLProvider.hpp"


std::string SQLProvider::getRequest(std::string fileName,  std::format_args args) {
    std::string request("SELECT {} FROM {}");
    std::string_view av (request);
    std::string paramRequest = std::vformat(av, args);
    return paramRequest;
}