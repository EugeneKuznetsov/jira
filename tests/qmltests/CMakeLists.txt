cmake_minimum_required(VERSION 3.16)

project(qmltests)

set(target ${PROJECT_NAME})

set(QML_IMPORT_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/imports" CACHE INTERNAL "Hello QtCreator! ;-)")

set(qmltests tst_issue.qml tst_jira.qml tst_options.qml)
set(header main.h)
set(sources main.cpp)

add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${target} ${headers} ${sources} ${resources} ${qmltests})

target_link_libraries(${target} Qt5::QuickTest Qt5::Gui Qt5::Qml qmljiraplugin)
