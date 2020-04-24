cmake_minimum_required(VERSION 3.16)

set(target plugin_qmltypes)

set(headers jira.h options.h responsestatus.h resources/issue.h resources/user.h)
set(sources jira.cpp options.cpp responsestatus.cpp resources/issue.cpp resources/user.cpp)

add_library(${target} STATIC ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} PUBLIC Qt5::Qml)
