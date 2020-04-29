cmake_minimum_required(VERSION 3.16)

set(target plugin_qmltypes_external)

set(headers issue.h user.h)
set(sources issue.cpp user.cpp)

add_library(${target} OBJECT ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../")
target_link_libraries(${target} PUBLIC Qt5::Qml PRIVATE plugin_utils)
