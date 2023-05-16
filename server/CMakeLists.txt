cmake_minimum_required(VERSION 3.13)
project(server)

set (CMAKE_CXX_STANDARD 20)

set(server_LIBRARIES)
set(server_INCLUDE_DIRS)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ~/boost_1_82_0)
target_link_libraries(${PROJECT_NAME} PUBLIC DBManager recommendation DATAMODEL)


set(server_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(server_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)