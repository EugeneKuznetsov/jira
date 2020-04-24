cmake_minimum_required(VERSION 3.16)

set(target plugin_endpoints)

set(headers sessionendpoint.h issueendpoint.h searchendpoint.h userendpoint.h)
set(sources sessionendpoint.cpp issueendpoint.cpp searchendpoint.cpp userendpoint.cpp)

add_library(${target} STATIC ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} PUBLIC Qt5::Qml)
