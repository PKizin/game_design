cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(my_game)

file(GLOB SOURCES
    *.cpp
    classifier/src/*.cpp
    params/src/*.cpp
    item/src/*.cpp
    factory/src/*.cpp
)

include_directories(
    object
    classifier/inc
    params/inc
    item/inc
    factory/inc
)

add_executable(${PROJECT_NAME} ${SOURCES})