cmake_minimum_required(VERSION 3.0.0)
project(server_part VERSION 0.1.0)

#add_compile_options(--coverage)
#add_compile_options(-fsanitize=address)
#add_link_options(--coverage)

enable_testing()
find_package(GTest REQUIRED)
#include(GoogleTest)

add_subdirectory(lib/server)

add_executable(server_part src/main.cpp)
target_link_libraries(server_part server)