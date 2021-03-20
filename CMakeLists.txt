cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(FileStorage)

find_package(Qt5 COMPONENTS Core Quick Network REQUIRED)

add_subdirectory(server)
add_subdirectory(client)