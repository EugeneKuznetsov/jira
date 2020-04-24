cmake_minimum_required(VERSION 3.16)

set(target plugin_network)

set(headers session.h reply.h)
set(sources session.cpp reply.cpp)

add_library(${target} STATIC ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} PUBLIC Qt5::Network)
