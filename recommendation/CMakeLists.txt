cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(recommendation)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.hpp)
set(vect_HEADERS ../vectorization/include)
set(filt_HEADERS ../filtering/include)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC src include)
target_link_libraries(${PROJECT_NAME} vectorization filtering DATAMODEL)
include_directories(src include ${vect_HEADERS} ${filt_HEADERS})
