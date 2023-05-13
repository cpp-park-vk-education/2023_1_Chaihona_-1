#include "SQLProvider.hpp"
#include <dirent.h>


//TODO: проверка на то, что существует директория; на то, что в ней есть скрипты;
SQLProvider::SQLProvider(std::string path) {
    auto dirPath = path.c_str();
    auto dir = opendir(dirPath);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            std::ifstream requestFile(path + entry->d_name);
            std::string reqName = entry->d_name;
            reqName = reqName.substr(0, reqName.size() - 4); //  отрезаем от имени скрипта расширение
            scripts[reqName] = std::string((std::istreambuf_iterator<char>(requestFile)), std::istreambuf_iterator<char>());
        }
    }
}


//TODO: проверка количества аргументов, проверка существования запроса
std::string SQLProvider::getRequest(std::string fileName, std::format_args args) {
    std::string request = scripts[fileName];
    std::string_view sv(request);
    std::string paramRequest = std::vformat(sv, args);
    return paramRequest;
}