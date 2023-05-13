cmake_minimum_required(VERSION 3.5)

project(UI)

set(THIS_LIB_NAME UI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp *.ui)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(QT_VERSION_MAJOR 6)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(${THIS_LIB_NAME}  ${SOURCES})

set(UI_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(UI_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)

target_include_directories(${PROJECT_NAME} PUBLIC ~/boost_1_82_0)
target_include_directories(${PROJECT_NAME} PUBLIC ../lib/structures/include)
target_include_directories(${PROJECT_NAME} PUBLIC ../lib/Client/include)
target_link_libraries(UI PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets Client)