cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(my_game)

file(GLOB SOURCES
    *.cpp
    classifier/src/*.cpp
    params/src/*.cpp
)

include_directories(
    classifier/inc
    params/inc
)

add_executable(${PROJECT_NAME} ${SOURCES})