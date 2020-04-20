cmake_minimum_required(VERSION 3.16)

project(test_session)

find_package(Qt5 COMPONENTS Test Qml REQUIRED)

set(target ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

set(headers test_session.h)
set(sources test_session.cpp)

add_executable(${target} ${headers} ${sources})

target_include_directories(${target}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../plugin")

target_link_libraries(${target}
    PRIVATE Qt5::Test
    PRIVATE Qt5::Qml
    PRIVATE qmljiraplugin)
