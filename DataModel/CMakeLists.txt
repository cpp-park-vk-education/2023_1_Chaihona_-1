cmake_minimum_required(VERSION 3.13)
project(DATAMODEL)

set (CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-w -lm -g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")
# unknown warning at nlohmann =(

set(DATAMODEL_LIBRARIES)
set(DATAMODEL_INCLUDE_DIRS)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include ${NLOHMANN_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PQXX_LIB} ${PQ_LIB}  ${NLOHMANN_LIBRARIES})

set(DATAMODEL_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(DATAMODEL_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)