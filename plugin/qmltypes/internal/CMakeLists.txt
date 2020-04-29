cmake_minimum_required(VERSION 3.16)

set(target plugin_qmltypes_internal)

set(headers responsestatus.h)
set(sources responsestatus.cpp)

add_library(${target} OBJECT ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../")
target_link_libraries(${target} PUBLIC Qt5::Qml)
