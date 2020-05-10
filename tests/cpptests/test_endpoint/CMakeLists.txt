cmake_minimum_required(VERSION 3.16)

set(target test_endpoint)

set(headers test_endpoint.h)
set(sources test_endpoint.cpp)

add_executable(${target} ${headers} ${sources})
target_include_directories(${target} PRIVATE "${PROJECT_SOURCE_DIR}/plugin" PRIVATE "../../CuteMockServer/lib")
target_link_libraries(${target}
    PRIVATE Qt5::Test
    PRIVATE plugin_endpoints
    PRIVATE plugin_network
    PRIVATE plugin_qmltypes
    PRIVATE plugin_qmltypes_external
    PRIVATE plugin_qmltypes_internal
    PRIVATE plugin_utils
    PRIVATE cutemockserver)
