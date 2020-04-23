cmake_minimum_required(VERSION 3.16)

set(target plugin_network)

# it seems the following definition is not necessary
# because CMake adds already -D${PROJECT_NAME}_EXPORTS
add_compile_definitions(EXPORT_IMPORT_MAGIC)

set(headers session.h reply.h)
set(sources session.cpp reply.cpp)

add_library(${target} STATIC ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} Qt5::Network)
