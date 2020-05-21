cmake_minimum_required(VERSION 3.16)

set(target test_issue)

set(headers test_issue.h)
set(sources test_issue.cpp)

add_executable(${target} ${headers} ${sources})
target_link_libraries(${target} PRIVATE Qt5::Test PRIVATE plugin_qmltypes)
