cmake_minimum_required(VERSION 3.16)

project(qmljiraplugin VERSION 0.4.3)

find_package(Qt5 COMPONENTS Qml Network REQUIRED)

set(target ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/imports/Jira)

add_definitions(-DEXPORT_IMPORT_MAGIC)

set(imports
    imports/qmldir)
set(headers
    jiraqmlplugin.h
    logging.h
    globals.h
    network/session.h
    network/reply.h
    qmltypes/jira.h
    qmltypes/options.h
    qmltypes/responsestatus.h
    qmltypes/resources/issue.h
    endpoints/issueendpoint.h
    endpoints/searchendpoint.h
    endpoints/sessionendpoint.h)
set(sources
    jiraqmlplugin.cpp
    logging.cpp
    network/session.cpp
    network/reply.cpp
    qmltypes/jira.cpp
    qmltypes/options.cpp
    qmltypes/responsestatus.cpp
    qmltypes/resources/issue.cpp
    endpoints/issueendpoint.cpp
    endpoints/searchendpoint.cpp
    endpoints/sessionendpoint.cpp)

add_library(${target}
    SHARED ${sources} ${headers} ${imports})

target_include_directories(${target}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${target}
    PRIVATE Qt5::Qml
    PRIVATE Qt5::Network)

foreach(import ${imports})
    add_custom_command(TARGET ${target}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/${import}" ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
endforeach()
