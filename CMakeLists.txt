cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_PREFIX_PATH /home/andrzeju/Qt/5.8/gcc_64/lib/cmake/)
#set(CMAKE Qt5Core_DIR /home/andrzeju/Qt/5.8/gcc_64/lib/cmake/Qt5Core/)

project(translate)
option(TESTS_ENABLED "Enable tests build" ON)

set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_DESCRIPTION "Translate library")
set(PROJECT_AUTHOR "Danil Maksimov")
set(QT_VERSION_REQ "5.8")

find_package(Qt5 ${QT_VERSION_REQ} REQUIRED COMPONENTS Core Widgets)

add_subdirectory(src)
if(TESTS_ENABLED)
	enable_testing()
	add_subdirectory(test)
endif()

# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()