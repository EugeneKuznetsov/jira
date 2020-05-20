cmake_minimum_required(VERSION 3.16)

set(target plugin_endpoints)

generate_endpoints("${PROJECT_SOURCE_DIR}/plugin/ifgenerator/wadl/jira-rest-plugin_8.8.1.wadl" "${CMAKE_CURRENT_BINARY_DIR}/proxies")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include("${CMAKE_CURRENT_BINARY_DIR}/proxies/sessionendpointproxy.cmake")
include("${CMAKE_CURRENT_BINARY_DIR}/proxies/issueendpointproxy.cmake")
include("${CMAKE_CURRENT_BINARY_DIR}/proxies/searchendpointproxy.cmake")
include("${CMAKE_CURRENT_BINARY_DIR}/proxies/userendpointproxy.cmake")

set(headers sessionendpoint.h issueendpoint.h searchendpoint.h userendpoint.h)
set(sources sessionendpoint.cpp issueendpoint.cpp searchendpoint.cpp userendpoint.cpp)

add_library(${target} OBJECT ${headers} ${sources}
    ${generated_sessionendpointproxy}
    ${generated_issueendpointproxy}
    ${generated_searchendpointproxy}
    ${generated_userendpointproxy})
target_include_directories(${target}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(${target} PUBLIC ifgenerator PRIVATE plugin_qmltypes)
