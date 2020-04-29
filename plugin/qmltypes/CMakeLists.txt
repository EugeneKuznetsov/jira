cmake_minimum_required(VERSION 3.16)

set(target plugin_qmltypes)

add_subdirectory(internal)
add_subdirectory(external)

set(headers jira.h options.h)
set(sources jira.cpp options.cpp)

add_library(${target} OBJECT ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} PUBLIC Qt5::Qml PRIVATE plugin_network PRIVATE plugin_endpoints PRIVATE plugin_utils)
