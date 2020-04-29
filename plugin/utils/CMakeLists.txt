cmake_minimum_required(VERSION 3.16)

set(target plugin_utils)

set(headers logging.h)
set(sources logging.cpp)

add_library(${target} OBJECT ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} PUBLIC Qt5::Core)
