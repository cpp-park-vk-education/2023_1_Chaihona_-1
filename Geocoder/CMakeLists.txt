cmake_minimum_required(VERSION 3.13)
project(Geocoder)

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-lm -g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")

set(Geocoder_LIBRARIES)
set(Geocoder_INCLUDE_DIRS)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
set(Geocoder_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(Geocoder_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)