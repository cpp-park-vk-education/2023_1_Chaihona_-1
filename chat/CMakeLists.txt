cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(GPT)

find_package(nlohmann_json REQUIRED)
find_package(CURL REQUIRED)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.hpp)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC src include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)
include_directories(src include ${vect_HEADERS})
