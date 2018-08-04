cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(my_game)

file(GLOB SOURCES
    *.cpp
    *.h
    classifier/inc/*.h
    classifier/src/*.cpp
)

include_directories(
    classifier/inc
    classifier/src
)

add_executable(${PROJECT_NAME} ${SOURCES})