cmake_minimum_required(VERSION 3.16)

set(target test_session)

# it seems the following definition is not necessary
# because CMake adds already -D${PROJECT_NAME}_EXPORTS
add_compile_definitions(EXPORT_IMPORT_MAGIC)

set(headers test_session.h)
set(sources test_session.cpp)

add_executable(${target} ${headers} ${sources})
target_include_directories(${target} PRIVATE "${PROJECT_SOURCE_DIR}/plugin")
target_link_libraries(${target} Qt5::Test Qt5::Qml plugin_network plugin_utils)
