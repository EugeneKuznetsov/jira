cmake_minimum_required(VERSION 3.16)

set(target test_plugin)

set(QML_IMPORT_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/imports" CACHE INTERNAL "Hello QtCreator! ;-)")

set(qmltests tst_issue.qml tst_jira.qml tst_options.qml)
set(headers main.h)
set(sources main.cpp)

add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(${target} ${headers} ${sources} ${qmltests})
target_link_libraries(${target} PRIVATE Qt5::QuickTest PRIVATE Qt5::Gui PRIVATE Qt5::Qml PRIVATE libqmljiraplugin)
