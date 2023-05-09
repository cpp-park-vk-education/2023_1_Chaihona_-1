cmake_minimum_required(VERSION 3.0.0)
project(server_part VERSION 0.1.0)

#add_compile_options(--coverage)
#add_compile_options(-fsanitize=address)
#add_link_options(--coverage)

enable_testing()
find_package(GTest REQUIRED)
#include(GoogleTest)

#add_subdirectory(lib/server)
#add_subdirectory(lib/Client)
#include(lib/Client/CMakeLists.txt)

file(GLOB CPPS "lib/Client/src/*.cpp")
add_executable(server_part ${CPPS} src/main.cpp)
target_include_directories(server_part PUBLIC ~/park/boost_1_82_0)
target_include_directories(server_part PUBLIC lib/Client/include)
#target_link_libraries(server_part server)
#target_link_libraries(server_part client)