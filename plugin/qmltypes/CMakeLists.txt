cmake_minimum_required(VERSION 3.16)

set(target plugin_qmltypes)

set(headers user.h issue.h)
set(sources user.cpp issue.cpp)

add_library(${target} OBJECT ${headers} ${sources})
target_include_directories(${target} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(${target} PUBLIC Qt5::Qml)
