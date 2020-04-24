cmake_minimum_required(VERSION 3.16)

set(target example_issue)

set(QML_IMPORT_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/imports" CACHE INTERNAL "Hello QtCreator! ;-)")

set(sources main.cpp)
set(resources resources.qrc)

add_executable(${target} ${sources} ${resources})
target_link_libraries(${target} PRIVATE Qt5::Gui PRIVATE Qt5::Qml PRIVATE qmljiraplugin)
