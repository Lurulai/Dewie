cmake_minimum_required(VERSION 3.20)

set(target Dewie)
project(${target})

set(CMAKE_CXX_STANDARD 20)
set(EXTERNAL_LIB "${CMAKE_CURRENT_LIST_DIR}/external")

set(SFML_DIR "${EXTERNAL_LIB}/SFML/lib/cmake/SFML")
include_directories("${EXTERNAL_LIB}/SFML/include")
include_directories("${CMAKE_CURRENT_LIST_DIR}/inc" "${CMAKE_CURRENT_LIST_DIR}/src")

find_package(SFML 2.5 COMPONENTS graphics window audio system REQUIRED)

add_executable(${target} main.cpp src/Game.cpp inc/Game.h)

target_link_libraries(${target} sfml-graphics sfml-window sfml-audio sfml-system)