cmake_minimum_required(VERSION 3.20)

set(target Dewie)
project(${target})

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/external/SFML")
set(CMAKE_PREFIX_PATH "${SFML_DIR}/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

add_executable(${target} main.cpp)

target_link_libraries(Dewie sfml-graphics sfml-window)