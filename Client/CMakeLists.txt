cmake_minimum_required(VERSION 3.13)
project(Client)

set (CMAKE_CXX_STANDARD 20)

set(Client_LIBRARIES)
set(Client_INCLUDE_DIRS)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ~/boost_1_82_0)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC Structures)

set(Client_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(Client_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)