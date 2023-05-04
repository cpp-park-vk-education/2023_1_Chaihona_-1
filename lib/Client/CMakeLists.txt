add_library(client src/client.cpp)
target_include_directories(client PUBLIC include)
target_include_directories(server PUBLIC ~/park/boost_1_82_0)

add_subdirectory(tests)