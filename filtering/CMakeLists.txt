cmake_minimum_required(VERSION 3.13)
project(Filtering)
set (CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

include_directories(src
                    ../vectorization/src
                    ../text_processing/src)

add_library(${PROJECT_NAME} STATIC src/filtering.cpp
                                   include/filtering.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC include 
                                   ../text_processing/include
                                   ../vectorization/include)

target_link_libraries(${PROJECT_NAME} PUBLIC TextProcessing Vectorization)

add_executable(TEST test/filtering_test.cpp)

include_directories(TEST src
                    ../vectorization/src
                    ../text_processing/src)

target_include_directories(TEST PUBLIC include
                                        ../text_processing/include
                                        ../vectorization/include)

target_link_libraries(TEST ${GTEST_LIBRARIES})

enable_testing()
