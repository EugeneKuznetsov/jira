cmake_minimum_required(VERSION 3.16)

set(target test_restponse_status)

# it seems the following definition is not necessary
# because CMake adds already -D${PROJECT_NAME}_EXPORTS
add_compile_definitions(EXPORT_IMPORT_MAGIC)

set(headers test_response_status.h)
set(sources test_response_status.cpp)

add_executable(${target} ${headers} ${sources})
target_include_directories(${target} PRIVATE "${PROJECT_SOURCE_DIR}/plugin")
target_link_libraries(${target} PRIVATE Qt5::Test PRIVATE Qt5::Qml PRIVATE plugin_qmltypes PRIVATE plugin_network PRIVATE plugin_utils PRIVATE plugin_endpoints)
