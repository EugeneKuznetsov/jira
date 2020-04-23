cmake_minimum_required(VERSION 3.16)

set(target plugin_endpoints)

# it seems the following definition is not necessary
# because CMake adds already -D${PROJECT_NAME}_EXPORTS
add_compile_definitions(EXPORT_IMPORT_MAGIC)

set(headers sessionendpoint.h issueendpoint.h searchendpoint.h)
set(sources sessionendpoint.cpp issueendpoint.cpp searchendpoint.cpp)

add_library(${target} STATIC ${headers} ${sources})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${target} Qt5::Qml)
