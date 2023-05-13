cmake_minimum_required(VERSION 3.13)
project(chaihona)

set (CMAKE_CXX_STANDARD 20)

find_library(PQXX_LIB pqxx REQUIRED)
find_library(PQ_LIB pq REQUIRED)
find_package(CURL REQUIRED)

add_subdirectory(nlohmann)
add_subdirectory(DBWork)
add_subdirectory(DBConnection)
add_subdirectory(SQLProvider)
add_subdirectory(DataModel)
add_subdirectory(Geocoder)
add_subdirectory(DBManager)
add_subdirectory(DBRequests)
add_subdirectory(server)
add_subdirectory(recommendation)

add_executable(${PROJECT_NAME} dbMain.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PQXX_LIB} ${PQ_LIB} Recommendation server DBConnection DBWork SQLProvider DATAMODEL DBManager Geocoder DBRequests)

set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-w -lm -g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")

target_include_directories(${PROJECT_NAME} PUBLIC ${DBCONNECTION_INCLUDE_DIRS} ${DBWork_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC ~/boost_1_82_0)
 
target_link_libraries(${PROJECT_NAME} PRIVATE ${DBCONNECTION_LIBRARIES} ${DBWork_LIBRARIES})


if (${TEST})
    add_subdirectory(test/dbTest)
    add_subdirectory(test/dbRequestsTest)
    add_subdirectory(test/geocoderTest)
endif ()