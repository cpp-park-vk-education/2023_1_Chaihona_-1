cmake_minimum_required(VERSION 3.0)

project(recommendation)

set(SOURCES src/recommendation.cpp)
set(HEADERS include/recommendation.hpp)
set(vect_HEADERS ../vectorization/include)
set(filt_HEADERS ../filtering/include)

add_library(recommendation ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC src include)
target_link_libraries(recommendation vectorization filtering DATAMODEL)

include_directories(src include ${vect_HEADERS} ${filt_HEADERS})
