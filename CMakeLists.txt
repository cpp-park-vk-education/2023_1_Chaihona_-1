cmake_minimum_required(VERSION 3.0.0)

project(HobbyHub)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(structures)
add_subdirectory(Client)
add_subdirectory(UI)

target_include_directories(${PROJECT_NAME} PUBLIC ~/boost_1_82_0)
target_include_directories(${PROJECT_NAME} PUBLIC ${UI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${UI_LIBRARIES} Client Structures)