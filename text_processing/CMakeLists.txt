cmake_minimum_required(VERSION 3.13)
project(TextProcessing)
set (CMAKE_CXX_STANDARD 17)

# enable_testing()
# find_package(GTest REQUIRED)

set(CUR_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TextProcessing_INC_DIR ${CUR_DIR}/include)

file(GLOB SRC src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include)