add_library(server src/server.cpp)
target_include_directories(server PUBLIC include)
target_include_directories(server PUBLIC ~/park/boost_1_82_0)

add_subdirectory(tests)