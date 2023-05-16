cmake_minimum_required(VERSION 3.0)

project(vectorization)

set(vect_SOURCES src/text_processing.cpp src/tfidf_vectorization.cpp)
set(vect_HEADERS include/text_processing.hpp include/tfidf_vectorization.hpp)

add_library(vectorization STATIC ${vect_SOURCES} ${vect_HEADERS})

target_link_libraries(vectorization)

include_directories(src include)