cmake_minimum_required(VERSION 3.13)
project(db_test)

set (CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-lm -g -O0 -Wall -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${DBCONNECTION_INCLUDE_DIRS} ${DBWORK_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE DBConnection DBWork SQLProvider ${DBCONNECTION_INCLUDE_DIRS} GTest::GTest GTest::Main)