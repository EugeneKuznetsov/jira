cmake_minimum_required(VERSION 3.16)

set(target test_reply)

set(headers test_reply.h)
set(sources test_reply.cpp)

add_executable(${target} ${headers} ${sources})
target_include_directories(${target} PRIVATE "${PROJECT_SOURCE_DIR}/plugin")
target_link_libraries(${target} PRIVATE Qt5::Test PRIVATE Qt5::Qml PRIVATE plugin_network PRIVATE plugin_utils)
