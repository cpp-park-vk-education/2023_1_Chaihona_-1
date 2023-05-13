cmake_minimum_required(VERSION 3.13)
project(Vectorization)
set (CMAKE_CXX_STANDARD 17)

# enable_testing()
# find_package(GTest REQUIRED)

file(GLOB SRC src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include 
                                                  ../text_processing/include)
                                                  
target_link_libraries(${PROJECT_NAME} PUBLIC TextProcessing)