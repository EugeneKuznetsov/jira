cmake_minimum_required(VERSION 3.16)

project(qmljiraplugin VERSION 0.4.3 LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core Gui Qml Network Test QuickTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(plugin)
add_subdirectory(tests)
