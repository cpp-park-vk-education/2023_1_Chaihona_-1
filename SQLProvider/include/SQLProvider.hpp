#include <map>
#include <string>
#include <vector>
#include <format>
#include <iostream>

class SQLProvider {
private:    
    std::map<std::string, std::string> scripts;
public:
    SQLProvider() {}
    std::string getRequest(std::string fileName, std::format_args args);
};