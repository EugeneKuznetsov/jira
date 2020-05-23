cmake_minimum_required(VERSION 3.16)

set(target ${PROJECT_NAME})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/imports/Jira)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/imports/Jira)

add_subdirectory(ifgenerator)
add_subdirectory(endpoints)

set(imports imports/qmldir)
set(headers jiraqmlplugin.h jira.h)
set(sources jiraqmlplugin.cpp jira.cpp)

add_library(${target} SHARED ${sources} ${headers} ${imports})

if(WIN32)
    set_target_properties(${target} PROPERTIES PREFIX "")
endif()
set_target_properties(${target} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${target} PROPERTIES SOVERSION ${PROJECT_VERSION})

target_link_libraries(${target} PRIVATE plugin_endpoints)

foreach(import ${imports})
    add_custom_command(TARGET ${target}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/${import}" ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
endforeach()
