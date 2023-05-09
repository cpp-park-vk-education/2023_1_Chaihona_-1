cmake_minimum_required(VERSION 3.0.0)
project(server VERSION 0.1.0)

file(GLOB CPPS "src/*.cpp")
add_executable(server ${CPPS})

target_include_directories(server PUBLIC include)
target_include_directories(server PUBLIC ~/park/boost_1_82_0)

# add_subdirectory(tests)