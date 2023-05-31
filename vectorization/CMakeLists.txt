cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(vectorization)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.hpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC src include)
target_link_libraries(${PROJECT_NAME} )
include_directories(src include)
