cmake_minimum_required(VERSION 3.0)

project(filtering)

set(SOURCES src/filtering.cpp)
set(HEADERS include/filtering.hpp)
set(vect_HEADERS ../vectorization/include)

add_library(filtering ${SOURCES} ${HEADERS})

target_link_libraries(filtering vectorization)

include_directories(src include ${vect_HEADERS})