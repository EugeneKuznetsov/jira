cmake_minimum_required(VERSION 3.16)

set(target test_restponse_status)

set(headers test_response_status.h)
set(sources test_response_status.cpp)

add_executable(${target} ${headers} ${sources})
target_include_directories(${target} PRIVATE "${PROJECT_SOURCE_DIR}/plugin")
target_link_libraries(${target} PRIVATE Qt5::Test PRIVATE plugin_qmltypes_internal PRIVATE plugin_utils)
